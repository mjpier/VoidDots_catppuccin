/* Nord */
static const char fg[]              = "#ffffff";
static const char nord_fg[]         = "#D8DEE9";
static const char nord_fg2[]        = "#eceff4";
static const char nord_bg[]         = "#2E3440";
static const char nord_bg2[]        = "#4c566a";
static const char nord_blue[]       = "#81A1C1";
static const char nord_green[]      = "#8fbcbb";
static const char nord_cyan[]		= "#88c0d0";
static const char nord_blue2[]      = "#5e81ac";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { nord_fg2,  nord_bg,   nord_bg2   },
	[SchemeSel]  = { nord_bg,	nord_blue, nord_blue  },
};
