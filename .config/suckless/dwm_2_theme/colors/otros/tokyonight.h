static const char tn_bg[] 		= "#24283b";
static const char tn_bg2[] 		= "#1a1b26";
static const char tn_blue[] 	= "#7dcfff";
static const char tn_blue2[] 	= "#7aa2f7";
static const char tn_purple[]	= "#bb9af7";
static const char tn_orange[]	= "#ff9e64";
static const char tn_red[]		= "#f7768e";
static const char tn_fg[] 		= "#c0caf5";
static const char tn_white[] 	= "#ddeeff";
static const char tn_green[]	= "#9ece6a";
static const char tn_cyan[]		= "#73daca";
static const char tn_grey[]		= "#565f89";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm]	= { tn_fg,			tn_bg2,		tn_blue2 },
	[SchemeSel]		= { tn_white,		tn_bg2,		tn_blue2 },
	[SchemeUline]	= { tn_cyan,		tn_bg2,		tn_purple }, // border color of floating windows
	[SchemeUlineA]	= { tn_blue2,		tn_bg2,		tn_purple },
	[SchemeSymbol]	= { tn_green,		tn_bg,		tn_blue	},
	[SchemeTitle]	= { tn_blue2,		tn_bg2,		tn_blue },
	[SchemeCol1]	= { tn_red,			tn_bg,		tn_blue },
	[SchemeCol2]	= { tn_orange,		tn_bg,		tn_blue },
	[SchemeCol3]	= { tn_purple,		tn_bg2,		tn_blue },
	[SchemeCol4]	= { tn_grey,		tn_bg2,		tn_blue },
};
