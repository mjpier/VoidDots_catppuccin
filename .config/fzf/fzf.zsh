# Setup fzf
# ---------
if [[ ! "$PATH" == */home/mjpier/.config/fzf/bin* ]]; then
  export PATH="${PATH:+${PATH}:}/home/mjpier/.config/fzf/bin"
fi

# Auto-completion
# ---------------
[[ $- == *i* ]] && source "/home/mjpier/.config/fzf/shell/completion.zsh" 2> /dev/null

# Key bindings
# ------------
source "/home/mjpier/.config/fzf/shell/key-bindings.zsh"
