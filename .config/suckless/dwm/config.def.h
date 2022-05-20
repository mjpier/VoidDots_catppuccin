/* See LICENSE file for copyright and license details. */
#define TERMINAL "st"
/* appearance */
static const unsigned int borderpx  = 3;    // border pixel of windows
static const unsigned int snap      = 0;    // snap pixel
static const int showbar            = 1;    // 0 means no bar
static const int topbar             = 1;    // 0 means bottom bar
static const int colorfultag        = 1;    // 0 means use SchemeSel for selected tag
static const int vertpad            = 5;    // status padding vertical
static const int sidepad            = 5;    // status padding horizontal
static const unsigned int gappih    = 20;   // horiz inner gap between windows
static const unsigned int gappiv    = 20;   // vert inner gap between windows
static const unsigned int gappoh    = 20;   // horiz outer gap between windows and screen edge
static const unsigned int gappov    = 20;   // vert outer gap between windows and screen edge
static int smartgaps                = 0;    // 1 means no outer gap when there is only one window
static const char *fonts[]          = { "monospace:size=13", "Symbols Nerd Font:size=13:antialias=true:autohint=true" };

/* Colors */
static const char black[]           = "#1e1d2d";
static const char gray2[]           = "#282737"; // unfocused window border
static const char gray3[]           = "#585767";
static const char gray4[]           = "#282737";
static const char red[]             = "#f28fad"; // focused window border
static const char green[]           = "#abe9b3";
static const char blue[]            = "#96cdfb";
static const char red2[]            = "#f8bd96";
static const char yellow[]          = "#fae3b0";
static const char magenta[]         = "#d5aeea";

static const char *colors[][3]      = {
    /*              fg              bg      border  */
    [SchemeNorm]    = { gray3,      black,  gray2 },
    [SchemeSel]     = { gray4,      black,  red   },
    [SchemeTitle]   = { blue,       black,  black },
    [SchemeTag]     = { gray3,      black,  black },
    [SchemeTag1]    = { blue,       black,  black },
    [SchemeTag2]    = { red2,       black,  black },
    [SchemeTag3]    = { yellow,     black,  black },
    [SchemeTag4]    = { green,      black,  black },
    [SchemeTag5]    = { magenta,    black,  black },
    [SchemeLayout]  = { green,      black,  black },
};

typedef struct {
    const char *name;
    const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
const char *spcmd3[] = {TERMINAL, "-n", "spncmp", "-g", "120x34", "-e", "ncmpcpp", NULL };
const char *spcmd4[] = {TERMINAL, "-n", "spdiary", "-t", "spdiary", "-g", "120x34", "-e", "nvim", "+WikiJournal"};
const char *spcmd5[] = {TERMINAL, "-n", "spwiki", "-t", "spwiki", "-g", "120x34", "-e", "nvim", "+WikiIndex"};

static Sp scratchpads[] = {
    /* name     cmd  */
    {"spterm",  spcmd1},    // terminal
    {"spcalc",  spcmd2},    // calculator(bc)
    {"spncmp",  spcmd3},    // ncmpcpp music player
    {"spdiary", spcmd4},    // WikiJournal
    {"spwiki",  spcmd5},    // WikiIndex
};

/* staticstatus */
static const int statmonval = 0;

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4, SchemeTag5 };

static const unsigned int ulinepad      = 5;    // horizontal padding between the underline and tag
static const unsigned int ulinestroke   = 2;    // thickness / height of the underline
static const unsigned int ulinevoffset  = 0;    // how far above the bottom of the bar the line should appear
static const int ulineall               = 0;    // 1 to show underline on all tags, 0 for just the active ones

static const Rule rules[] = {
    /*  WM_CLASS(STRING) = instance, class */
    /*  WM_NAME(STRING) = title */
    /* class            instance    title                       tags mask       isfloating      monitor */
    { "Gimp",           NULL,       NULL,                       1 << 4,         0,              -1 },
    { "firefox",        NULL,       NULL,                       1 << 1,         0,              -1 },
    { "qutebrowser",    NULL,       NULL,                       1 << 1,         0,              -1 },
    { "Gcr-prompter",   NULL,       NULL,                       0,              1,              -1 },
    { "mpv",            NULL,       NULL,                       0,              1,              -1 },
    { "Lutris",         NULL,       NULL,                       1 << 4,         1,               1 },
    { "control.exe",    NULL,       NULL,                       1 << 4,         1,              -1 },
    { NULL,             NULL,       "Downloading file",         1 << 4,         1,              -1 },
    { NULL,             NULL,       "Wine Mono Installer",      1 << 4,         1,               1 },
    { NULL,             NULL,       "Battle.net Setup",         1 << 3,         1,               1 },
    { NULL,             NULL,       "Battle.net",               1 << 3,         1,               1 },
    { NULL,             NULL,       "World of Warcraft",        1 << 3,         0,              -1 },
    { "discord",        NULL,       "Discord",                  1 << 4,         1,               1 },
    { NULL,             NULL,       "Discord",                  1 << 4,         1,               1 },
    { "Steam",          NULL,       NULL,                       1 << 4,         1,               1 },
    { NULL,             NULL,       "Steam",                    1 << 4,         1,               1 },
    { "dota2",          NULL,       NULL,                       1 << 3,         0,              -1 },
    { "RimWorldLinux",  NULL,       NULL,                       1 << 3,         0,              -1 },
    { "Zenity",         NULL,       NULL,                       1 << 4,         1,              -1 },
    { "steam_proton",   NULL,       NULL,                       1 << 4,         1,              -1 },
    { NULL,             NULL,       "Friends List",             1 << 4,         1,               1 },
    { NULL,             NULL,       "Wine System Tray",         1 << 4,         1,               1 },
    { NULL,             NULL,       "Rockstar Games Launcher",  1 << 4,         1,              -1 },
    { NULL,             NULL,       "Grand Theft Auto V",       1 << 3,         0,              -1 },
    { NULL,             NULL,       "tremc",                    1 << 4,         0,               1 },
    { NULL,             NULL,       "notes",                    0,              1,              -1 },
    { NULL,             NULL,       "pulsemixer",               0,              1,              -1 },
    { NULL,             "spterm",   NULL,                       SPTAG(0),       1,              -1 },
    { NULL,             "spcalc",   NULL,                       SPTAG(1),       1,              -1 },
    { NULL,             "spncmp",   NULL,                       SPTAG(2),       1,              -1 },
    { NULL,             "spdiary",  NULL,                       SPTAG(3),       1,              -1 },
    { NULL,             "spwiki",   NULL,                       SPTAG(4),       1,              -1 },
};

/* layout(s) */
static const float mfact        = 0.50; // factor of master area size [0.05..0.95]
static const int nmaster        = 1;    // number of clients in master area
static const int resizehints    = 0;    // 1 means respect size hints in tiled resizals
static const int lockfullscreen = 1;    // 1 will force focus on the fullscreen window

#define FORCE_VSPLIT 1  // nrowgrid layout: force two clients to always split vertically
#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol   arrange function */
    { "[]=",    tile },                     // Default: Master on left, slaves on right
    { "TTT",    bstack },                   // Master on top, slaves on bottom

    { "[@]",    spiral },                   // Fibonacci spiral
    { "[\\]",   dwindle },                  // Decreasing in size right and leftward

    { "D[]",    deck },                     // Master on left, slaves in monocle-like mode on right
    { "[M]",    monocle },                  // All windows on top of eachother

    { "|M|",    centeredmaster },           // Master in middle, slaves on sides
    { ">M>",    centeredfloatingmaster },   // Same but master floats

    { "><>",    NULL },                     // no layout function means floating behavior
    { NULL,     NULL },
};

static const MonitorRule monrules[] = {
    /* monitor  tag layout  mfact   nmaster showbar topbar */
    {  1,       -1, 0,      -1,     -1,     0,      -1 }, // Second monitor
    { -1,       -1, 0,      -1,     -1,    -1,      -1 }, // Primary monitor default
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

#include <X11/XF86keysym.h>

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };

static Key keys[] = {
    /* modifier                 key         function            argument */
    { MODKEY,                   XK_Return,  spawn,              {.v = termcmd } },
    { ALTKEY,                   XK_b,       togglebar,          {0} },
    { MODKEY,                   XK_j,       focusstack,         {.i = +1 } },
    { MODKEY,                   XK_k,       focusstack,         {.i = -1 } },
    { ALTKEY,                   XK_comma,   incnmaster,         {.i = +1 } },
    { ALTKEY,                   XK_period,  incnmaster,         {.i = -1 } },
    { MODKEY,                   XK_h,       setmfact,           {.f = -0.05} },
    { MODKEY,                   XK_l,       setmfact,           {.f = +0.05} },
    { MODKEY|ShiftMask,         XK_h,       setcfact,           {.f = +0.25} },
    { MODKEY|ShiftMask,         XK_l,       setcfact,           {.f = -0.25} },
    { MODKEY|ShiftMask,         XK_o,       setcfact,           {.f =  0.00} },
    { MODKEY|ShiftMask,         XK_j,       zoom,               {0} },
    { MODKEY,                   XK_Tab,     view,               {0} },
    { MODKEY,                   XK_q,       killclient,         {0} },
    { MODKEY,                   XK_t,       setlayout,          {.v = &layouts[0]} }, // tile
    { MODKEY|ShiftMask,         XK_t,       setlayout,          {.v = &layouts[1]} }, // bstack
    { MODKEY,                   XK_y,       setlayout,          {.v = &layouts[2]} }, // spiral
    { MODKEY|ShiftMask,         XK_y,       setlayout,          {.v = &layouts[3]} }, // dwindle
    { MODKEY,                   XK_u,       setlayout,          {.v = &layouts[4]} }, // deck
    { MODKEY|ShiftMask,         XK_u,       setlayout,          {.v = &layouts[5]} }, // monocle
    { MODKEY,                   XK_i,       setlayout,          {.v = &layouts[6]} }, // centeredmaster
    { MODKEY|ShiftMask,         XK_i,       setlayout,          {.v = &layouts[7]} }, // centeredfloatingmaster
    { MODKEY,                   XK_space,   setlayout,          {0} },
    { MODKEY|ShiftMask,         XK_space,   togglefloating,     {0} },
    { MODKEY,                   XK_f,       togglefullscreen,   {0} },
    { MODKEY|ShiftMask,         XK_c,       togglecolorfultag,  {0} },
    { MODKEY,                   XK_0,       view,               {.ui = ~0 } },
    { MODKEY|ShiftMask,         XK_0,       tag,                {.ui = ~0 } },
    { ALTKEY,                   XK_Tab,     focusmon,           {.i = +1 } },
    { ALTKEY|ShiftMask,         XK_h,       tagmon,             {.i = -1 } },
    { ALTKEY|ShiftMask,         XK_l,       tagmon,             {.i = +1 } },
    { ALTKEY,                   XK_minus,   incrgaps,           {.i = -3 } },
    { ALTKEY,                   XK_equal,   incrgaps,           {.i = +3 } },
    { MODKEY,                   XK_a,       togglegaps,         {0} },
    { MODKEY|ShiftMask,         XK_a,       defaultgaps,        {0} },
    TAGKEYS(                    XK_1,                            0)
    TAGKEYS(                    XK_2,                            1)
    TAGKEYS(                    XK_3,                            2)
    TAGKEYS(                    XK_4,                            3)
    TAGKEYS(                    XK_5,                            4)
    { MODKEY,                   XK_Escape,  spawn,              SHCMD("powermenu") },
    { MODKEY,                   XK_r,       spawn,              SHCMD("dmenu-query") },
    { MODKEY,                   XK_x,       togglescratch,      {.ui = 0} }, // spterm
    { MODKEY|ShiftMask,         XK_b,       togglescratch,      {.ui = 1} }, // bc
    { MODKEY|ShiftMask,         XK_m,       togglescratch,      {.ui = 2} }, // ncmpcpp
    { MODKEY|ShiftMask,         XK_d,       togglescratch,      {.ui = 3} }, // diary
    { MODKEY|ShiftMask,         XK_n,       togglescratch,      {.ui = 4} }, // wiki
    { MODKEY,                   XK_Delete,  spawn,              SHCMD("varecord kill") },
    { ALTKEY,                   XK_Delete,  spawn,              SHCMD("camtoggle kill") },
    { MODKEY,                   XK_d,       spawn,              SHCMD("dmenu_run") },
    { MODKEY,                   XK_F1,      spawn,              SHCMD("upnotify") },
    { MODKEY,                   XK_F2,      spawn,              SHCMD("crontoggle") },
    { MODKEY,                   XK_F3,      spawn,              SHCMD("gtok") },
    { MODKEY,                   XK_F4,      spawn,              SHCMD("gameon") },
    { MODKEY|ShiftMask,         XK_F4,      spawn,              SHCMD("picomtoggle") },
    { MODKEY,                   XK_F5,      spawn,              SHCMD("varecord") },
    { MODKEY,                   XK_F6,      spawn,              SHCMD("takepic") },
    { MODKEY,                   XK_F7,      spawn,              SHCMD("cluttertoggle") },
    { MODKEY,                   XK_F8,      spawn,              SHCMD(TERMINAL " -e pulsemixer; pkill -RTMIN+17 dwmblocks") },
    { MODKEY,                   XK_F9,      spawn,              SHCMD("dmenu-mount") },
    { MODKEY,                   XK_F10,     spawn,              SHCMD("dmenu-unmount") },
    { MODKEY,                   XK_F11,     spawn,              SHCMD("mpv --no-cache --no-osc --no-input-default-bindings --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
    { MODKEY,                   XK_F12,     spawn,              SHCMD(TERMINAL " -e tremc") },
    { ALTKEY|ShiftMask,         XK_F12,     spawn,              SHCMD("torrtoggle") },
    { ALTKEY,                   XK_F12,     spawn,              SHCMD("torrclear") },
    { MODKEY,                   XK_Insert,  spawn,              SHCMD("showclip") },
    { MODKEY,                   XK_grave,   spawn,              SHCMD("emojis") },
    { MODKEY,                   XK_b,       spawn,              SHCMD("$BROWSER") },
    { MODKEY,                   XK_c,       spawn,              SHCMD("calnotify") },
    { MODKEY,                   XK_g,       spawn,              SHCMD(TERMINAL " -e htop") },
    { MODKEY,                   XK_o,       spawn,              SHCMD(TERMINAL " -e lf") },
    { MODKEY,                   XK_n,       spawn,              SHCMD(TERMINAL " -e newsboat; pkill -RTMIN+19 dwmblocks") },
    { MODKEY,                   XK_p,       spawn,              SHCMD("mpc toggle") },
    { ALTKEY,                   XK_m,       spawn,              SHCMD(TERMINAL " -e neomutt; pkill -RTMIN+18 dwmblocks") },
    { MODKEY,                   XK_equal,   spawn,              SHCMD("audiobar 0 +5; pkill -RTMIN+17 dwmblocks") },
    { MODKEY,                   XK_minus,   spawn,              SHCMD("audiobar 0 -5; pkill -RTMIN+17 dwmblocks") },
    { MODKEY,                   XK_comma,   spawn,              SHCMD("mpc prev") },
    { MODKEY,                   XK_period,  spawn,              SHCMD("mpc next") },
    { MODKEY|ShiftMask,         XK_comma,   spawn,              SHCMD("mpc seek -10") },
    { MODKEY|ShiftMask,         XK_period,  spawn,              SHCMD("mpc seek +10") },
    { MODKEY,                   XK_Print,   spawn,              SHCMD("screenshot") },
    { MODKEY|ShiftMask,         XK_Print,   spawn,              SHCMD("keyshot") },
    { MODKEY|ShiftMask,         XK_z,       spawn,              SHCMD("manterm") },
    { MODKEY,                   XK_z,       spawn,              SHCMD("manzathura") },
    { MODKEY,                   XK_s,       spawn,              SHCMD("searchplaylist") },
    { MODKEY,                   XK_w,       spawn,              SHCMD("searchweb") },
    { ALTKEY,                   XK_space,   spawn,              SHCMD("dunstctl close") },
    { ALTKEY|ShiftMask,         XK_space,   spawn,              SHCMD("dunstctl close-all") },
    { ALTKEY|ShiftMask,         XK_comma,   spawn,              SHCMD("dunstctl history-pop") },

    /* XF86Keys */
    { 0,    XK_Print,                   spawn,              SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
    { 0,    XF86XK_AudioRaiseVolume,    spawn,              SHCMD("pulsevol inc; pkill -RTMIN+17 dwmblocks") },
    { 0,    XF86XK_AudioLowerVolume,    spawn,              SHCMD("pulsevol dec; pkill -RTMIN+17 dwmblocks") },
    { 0,    XF86XK_AudioMute,           spawn,              SHCMD("pulsevol mute; pkill -RTMIN+17 dwmblocks") },
    { 0,    XF86XK_MonBrightnessUp,     spawn,              SHCMD("xbacklight +10") },
    { 0,    XF86XK_MonBrightnessDown,   spawn,              SHCMD("xbacklight -10") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click            event mask  button      function        argument */
    { ClkLtSymbol,      0,          Button1,    setlayout,      {0} },
    { ClkLtSymbol,      0,          Button3,    setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,      0,          Button2,    zoom,           {0} },
    { ClkStatusText,    0,          Button1,    sigstatusbar,   {.i = 1} },
    { ClkStatusText,    0,          Button2,    sigstatusbar,   {.i = 2} },
    { ClkStatusText,    0,          Button3,    sigstatusbar,   {.i = 3} },
    { ClkClientWin,     MODKEY,     Button1,    movemouse,      {0} },
    { ClkClientWin,     MODKEY,     Button2,    togglefloating, {0} },
    { ClkClientWin,     MODKEY,     Button3,    resizemouse,    {0} },
    { ClkTagBar,        0,          Button1,    view,           {0} },
    { ClkTagBar,        0,          Button3,    toggleview,     {0} },
    { ClkTagBar,        MODKEY,     Button1,    tag,            {0} },
    { ClkTagBar,        MODKEY,     Button3,    toggletag,      {0} },
};

