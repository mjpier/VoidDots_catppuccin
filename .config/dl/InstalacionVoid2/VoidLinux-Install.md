# Void Linux Musl Installation (SATA M.2, btrfs, LVM, full disk encryption using LUKS, SSD TRIM)

This is a personal installation guide Void Linux :-)

## Basics
- Laptop: Acer Swift 3
- Void Linux installer version: 2021-09-30 (x86_64 musl)

## Features
This guide explains how to set up Void Linux:
- On an SATA M.2 disk
- Using full disk encryption - **including** /boot, with LUKS + LVM
- Uses btrfs as filesystem

## Important notes
- SSD/NVMe trimming **only** works if it is enabled on all intermediate layers, which in this case means LUKS, LVM and btrfs

## The process

### Pre-chroot
```bash
# Boot Void live system and login using root:voidlinux

bash
loadkeys es

cp /etc/wpa_supplicant/wpa_supplicant.conf /etc/wpa_supplicant/wpa_supplicant-<interface>.conf
wpa_passphrase <SSID> <password> >> /etc/wpa_supplicant/wpa_supplicant-<interface>.conf
wpa_supplicant -B -i <interface> -c /etc/wpa_supplicant/wpa_supplicant-<interface>.conf

# Partition the disk
lsblk
wipefs -af /dev/sda

fdisk /dev/sda
# g to create a new GTP partition table
# n new partition with +512M
# t 1 to set partition type to EFI
# n new partition with remaining space

    Create GPT partition table
    Command (m for help): g

    Create EFI System Partition (ESP)
    Command (m for help): n
    Partition number (1-128, default 1): (enter for default)
    First sector (2048-500118158, default 2048): (enter for default)
    Last sector, +/-sectors or +/-size{K,M,G,T,P}...): +512M (choose 128M to 1G)
    Do you want to remove the signature? [Y]es/[N]o: y
    Command (m for help): t
    Partition type or alias (type L to list all): 1

    Create the root partition
    Command (m for help): n
    Partition number (2-128, default 2): (enter for default)
    First sector (1050624-500118158, default 1050624): (enter for default)
    Last sector, +/-sectors or +/-size{K,M,G,T,P}...): (enter for default)

    Write changes to the disk
    Command (m for help): w

# Set Up Encryption
cryptsetup luksFormat --type=luks1 /dev/sda2
cryptsetup open /dev/sda2 crypt

# Prepare LVM
vgcreate vg0 /dev/mapper/crypt
lvcreate --name swap -L 16G vg0
lvcreate --name void -l +100%FREE vg0

# Filesystems
mkfs.vfat -n BOOT -F 32 /dev/sda1
mkswap /dev/mapper/vg0-swap
mkfs.btrfs -L void /dev/mapper/vg0-void

mount -o rw,noatime,ssd,compress=lzo,space_cache,commit=60 /dev/mapper/vg0-void /mnt
btrfs subvolume create /mnt/@
btrfs subvolume create /mnt/@home
btrfs subvolume create /mnt/@snapshots
umount /mnt
mount -o rw,noatime,ssd,compress=lzo,space_cache,commit=60,subvol=@ /dev/mapper/vg0-void /mnt
mkdir /mnt/home
mkdir /mnt/.snapshots
mount -o rw,noatime,ssd,compress=lzo,space_cache,commit=60,subvol=@home /dev/mapper/vg0-void /mnt/home/
mount -o rw,noatime,ssd,compress=lzo,space_cache,commit=60,subvol=@snapshots /dev/mapper/vg0-void /mnt/.snapshots/
mkdir -p /mnt/boot/efi
mount -o rw,noatime /dev/sda1 /mnt/boot/efi/
mkdir -p /mnt/var/cache
btrfs subvolume create /mnt/var/cache/xbps
btrfs subvolume create /mnt/var/tmp
btrfs subvolume create /mnt/srv

# Install the System and make Chroot
export XBPS_ARCH=x86_64-musl
xbps-install -Sy -R https://alpha.de.repo.voidlinux.org/current/musl -r /mnt base-minimal btrfs-progs cryptsetup lvm2 bash less man-pages e2fsprogs pciutils usbutils iproute2 dhcpcd kbd ethtool kmod iputils xfsprogs f2fs-tools dosfstools traceroute neovim nano ncurses opendoas acpid eudev file mdocml wpa_supplicant iw zsh dbus git
mount -t proc proc /mnt/proc/
mount -t sysfs sys /mnt/sys/
mount -o bind /dev /mnt/dev
mount -t devpts pts /mnt/dev/pts
cp -L /etc/resolv.conf /mnt/etc/
cp -L /etc/wpa_supplicant/wpa_supplicant-<interface>.conf /mnt/etc/wpa_supplicant/
chroot /mnt /bin/bash
```

### Post-chroot
```bash
passwd root
chown root:root /
chmod 755 /
echo VoidOS > /etc/hostname
cat <<EOF > /etc/rc.conf
    # /etc/rc.conf - system configuration for void

    HOSTNAME="VoidOS"
    HARDWARECLOCK="UTC"
    TIMEZONE="America/Lima"
    KEYMAP="la-latin1"
EOF

export UEFI_UUID=$(blkid -s UUID -o value /dev/sda1)
export LUKS_UUID=$(blkid -s UUID -o value /dev/sda2)
export ROOT_UUID=$(blkid -s UUID -o value /dev/mapper/vg0-void)
export SWAP_UUID=$(blkid -s UUID -o value /dev/mapper/vg0-swap)

cat <<EOF > /etc/fstab
    UUID=$ROOT_UUID / btrfs rw,noatime,ssd,compress=lzo,space_cache,commit=60,subvol=@ 0 1
    UUID=$ROOT_UUID /home btrfs rw,noatime,ssd,compress=lzo,space_cache,commit=60,subvol=@home 0 2
    UUID=$ROOT_UUID /.snapshots btrfs rw,noatime,ssd,compress=lzo,space_cache,commit=60,subvol=@snapshots 0 2
    UUID=$UEFI_UUID /boot/efi vfat defaults,noatime 0 2
    UUID=$SWAP_UUID none swap defaults 0 1
    tmpfs /tmp tmpfs defaults,noatime,mode=1777 0 0
EOF
```

### Software Install
```bash
# Xorg
xbps-install -S xorg-minimal xwininfo xprop xdpyinfo xset xsetroot xrdb ## xorg-server-devel xterm

# Video Drivers and Display Server
xbps-install mesa-dri vulkan-loader mesa-vulkan-intel intel-video-accel

# Core
xbps-install -S xcape setxkbmap efivar mlocate readline-devel lm_sensors pkg-config man-db wget zip unzip ## unrar
xbps-install -S dosfstools ntfs-3g xdg-user-dirs xtools xdg-utils xclip xdo xdotool mediainfo elogind bc tree

# Security and others
xbps-install -S VeraCrypt firejail keepassxc zramen gpick qt5ct

# Audio
#doas xbps-install -S pulseaudio alsa-plugins-pulseaudio pulsemixer pamixer ## Do not use
#doas ln -s /etc/sv/pulseaudio/ /var/service ## Do not use
xbps-install -S pipewire pamixer

# Others
xbps-install -S Thunar gvfs gvfs-mtp
xbps-install -S libreoffice-writer libreoffice-calc bibletime gimp
xbps-install -S calcurse yt-dlp ffmpeg maim sxiv feh ImageMagick ## xwallpaper
xbps-install -S picom mpd mpc mpv ncmpcpp ## newsboat rsync
xbps-install -S zathura zathura-pdf-mupdf poppler python3-adblock jq ## cronie
xbps-install -S dunst libnotify htop bat moreutils git curl ## gucharmap transmission tremc 
xbps-install -S qutebrowser lf upower unclutter-xfixes telegram-desktop ## qrencode steam Signal-Desktop
xbps-install -S base-devel make libXrandr-devel libX11-devel libXft-devel libXinerama-devel ## imlib2-devel harfbuzz-devel

# Fonts
xbps-install -S dejavu-fonts-ttf noto-fonts-ttf noto-fonts-emoji
xbps-install -S liberation-fonts-ttf font-inconsolata-otf  ## terminus-font font-awesome

# Mail (I do not use Mail)
#doas xbps-install -S neomutt notmuch isync msmtp

# Other for personal work  
lxappearance xbacklight xarchiver geany xmodmap xorg-fonts ## Do not use xf86-video-intel

```


### Kernel installation, grub and final configuration
```bash
xbps-install -Sy linux5.15 linux5.15-headers linux-firmware-intel linux-firmware-network dracut
xbps-install -fy linux5.15
xbps-install -y grub-x86_64-efi grub-btrfs

cat <<EOF >> /etc/default/grub
    GRUB_ENABLE_CRYPTODISK=y
EOF

sed -i "/GRUB_CMDLINE_LINUX_DEFAULT=/s/\"$/ rd.auto=1 cryptdevice=UUID=$LUKS_UUID:lvm:allow-discards&/" /etc/default/grub
dd bs=512 count=4 if=/dev/urandom of=/boot/volume.key
cryptsetup luksAddKey /dev/sda2 /boot/volume.key
chmod 000 /boot/volume.key
chmod -R g-rwx,o-rwx /boot

cat <<EOF >> /etc/crypttab
    crypt /dev/sda2 /boot/volume.key luks
EOF

cat <<EOF >> /etc/dracut.conf.d/10-crypt.conf
    install_items+=" /boot/volume.key /etc/crypttab "
EOF

echo 'add_dracutmodules+=" crypt btrfs lvm resume "' >> /etc/dracut.conf
echo 'tmpdir=/tmp' >> /etc/dracut.conf
dracut --force --hostonly --kver $(ls -t /lib/modules | sed 1q)
mkdir /boot/grub
grub-mkconfig -o /boot/grub/grub.cfg
grub-install --target=x86_64-efi --efi-directory=/boot/efi --bootloader-id=void --boot-directory=/boot  --recheck

# Ending
xbps-reconfigure -fa
exit
umount -R /mnt
shutdown -r now
```

###  Post installation
```bash

# Activate services and create user
ln -srf /etc/sv/{dhcpcd,wpa_supplicant,dbus,elogind,pipewire,pipewire-pulse,polkitd} /var/service

# Network WIFI configuration
wpa_cli

    > scan
    OK
    <3>CTRL-EVENT-SCAN-STARTED
    <3>CTRL-EVENT-SCAN-RESULTS
    > scan_results

    > add_network
    0
    > set_network 0 ssid "<nama_ssid>"
    OK
    > set_network 0 psk "<password_dari_ssid>"
    OK

    > select_network 0
    OK
    > enable_network 0
    OK
    > save_config
    OK
    > quit
# to see the list of networks that have been added using list_networks to check if you are connected to the internet can ping

# Normal user and privileges
useradd -m -s /bin/zsh -U -G wheel,disk,audio,video,storage,network,xbuilder,input,users YOUR_USER
passwd YOUR_USER

# Remove the Intel DDX driver to ensure xorg uses modesetting
echo 'ignorepkg=xf86-video-intel' >> /etc/xbps.d/10-ignore.conf
xbps-remove xf86-video-intel

# Remove Sudo. Just work with doas
echo "ignorepkg=sudo" > /etc/xbps.d/10-ignore.conf
xbps-remove sudo

touch /etc/doas.conf
echo "permit :wheel" > /etc/doas.conf
echo "permit persist :wheel" >> /etc/doas.conf

# Remove some unused Runit services
rm /var/service/{agetty-tty4,agetty-tty5,agetty-tty6}
rm /var/service/sshd

# Logout and login with YOUR_USER
exit
login

# Clone Dotfiles
git clone https://github.com/mjpier/VoidDots
cd VoidDots

cp -r .config /home/YOUR_USER
cp -r .local /home/YOUR_USER
cp -r .mpd /home/YOUR_USER
cp -r .ncmpcpp /home/YOUR_USER

cd /home/YOUR_USER/.config/suckless
compile suckless (dwm, dmenu, dwmblocks, st, slock)

rm /home/YOUR_USER/.bash*
rm /home/YOUR_USER/.zshrc
rm /home/YOUR_USER/.inputrc

cp -r .zshenv /home/YOUR_USER
cp -r .xinitrc /home/YOUR_USER

mkdir -p /home/YOUR_USER/.config/dl/{torrent,others,pics,docs}
mkdir -p /home/YOUR_USER/.config/dl/torrent/{completed,incomplete}
mkdir -p /home/YOUR_USER/.local/share/qutebrowser/greasemonkey

doas usermod -aG _pipewire YOUR_USER

reboot
```

###  Others (after logging in as normal user)
```bash
# Void-packages and xbps-src
git clone https://github.com/void-linux/void-packages.git
cd void-packages
./xbps-src binary-bootstrap
echo XBPS_ALLOW_RESTRICTED=yes >> etc/conf
    - For builde a package:
        ./xbps-src pkg <package_name>
        doas xbps-install -S xtools
        cd void-packages/masterdir
        xi <package_name>


# libxft patch
cd void-packages/srcpkgs/libXft
mkdir patches
# Copy the patch inside patches directory:
   cd void-packages
   ./xbps-src pkg -f libXft
   doas xbps-install -R ./hostdir/binpkgs -f libXft
   doas xbps-install -R ./hostdir/binpkgs -f libXft-devel
   doas xbps-pkgdb -m repolock libXft  # avoid overwritten by updates


# Picom-ibhagwan (for rounded corners and transparencies)
git clone https://github.com/ibhagwan/picom-ibhagwan-template
mv picom-ibhagwan-template <path_void-packages>/srcpkgs/picom-ibhagwan
cd <path_void-packages>
./xbps-src pkg picom-ibhagwan
doas xbps-install --repository=hostdir/binpkgs picom-ibhagwan


# Qemu Install
doas xbps-install -S dbus qemu libvirt virt-manager
doas xbps-install -S bridge-utils iptables
ln -srf /etc/sv/{dbus,libvirtd,virtlockd,virtlogd} /var/service

# Open and edit libvirt.conf with root permissions
nvim /etc/libvirt/libvirt.conf

    unix_sock_group = libvirt
    unix_sock_rw_perms = "0700"

doas usermod -a -G libvirt $(whoami)
newgrp libvirt

# Restart services
doas sv restart libvirtd
doas sv restart virtlockd
doas sv restart virtlogd


# For applications QT5
doas xbps-install -S qt5ct
# add in .zshenv
   export QT_QPA_PLATFORMTHEME="qt5ct"

# Update fonts cache
fc-cache -fv


# For test dunst 
notify-send -u low -t 0 "Low sumary" "Low body"
notify-send -u low -t 0 "Low sumary" "Low body"
notify-send -u normal -t 0 "Normal sumary" "Normal body"
notify-send -u critical -t 0 "Critical sumary" "Critical body"
notify-send -u critical -t 0 "test" "Critical body"

sed -i 's/issue_discards = 0/issue_discards = 1/' /etc/lvm/lvm.conf

```

###  To rescue the system enter CHROOT from liveCD
```bash
cryptsetup open /dev/sda2 crypt
lvchange -ay /dev/vg0/void
lvchange -ay /dev/vg0/swap
lvdisplay vg0

mount -o rw,noatime,ssd,compress=lzo,space_cache,commit=60,subvol=@ /dev/vg0/void /mnt
mount -o rw,noatime,ssd,compress=lzo,space_cache,commit=60,subvol=@home /dev/vg0/void /mnt/home/
mount -o rw,noatime /dev/sda1 /mnt/boot/efi/
mount -t proc proc /mnt/proc/
mount -t sysfs sys /mnt/sys/
mount -o bind /dev /mnt/dev
mount -t devpts pts /mnt/dev/pts
chroot /mnt /bin/bash

# After solving reboot the system
exit
umount -R /mnt
shutdown -r now
```

## References
As per "standing on the shoulders of giants", most of the information in this guide was no
discovered by myself, but rather assembled from various existing guides, which I want to list
here to give credit where credit is due:

[1] https://gist.github.com/tobi-wan-kenobi/bff3af81eac27e210e1dc88ba660596e

[2] https://www.yubico.com/resources/glossary/static-password/

[3] https://gist.github.com/gbrlsnchs/9c9dc55cd0beb26e141ee3ea59f26e21

[4] https://wiki.voidlinux.org/Full_Disk_Encryption_w/Encrypted_Boot

[5] https://gist.github.com/mattiaslundberg/8620837

[6] http://blog.neutrino.es/2013/howto-properly-activate-trim-for-your-ssd-on-linux-fstrim-lvm-and-dmcrypt/
