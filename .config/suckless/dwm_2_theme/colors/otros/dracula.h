static const char drac_bg[] 		= "#282a36";
static const char drac_bg2[]		= "#383a59";
static const char drac_bg3[] 		= "#1e1f29";
static const char drac_sel[] 		= "#5f6a8e";
static const char drac_sel2[]		= "#bd93f9";
static const char drac_sel3[]		= "#664c90";
static const char drac_fg[] 		= "#f8f8f2";
static const char drac_fg2[] 		= "#9da0c6";
static const char drac_green[]		= "#50fa7b";
static const char drac_cyan[]		= "#8be9fd";
static const char drac_yellow[]		= "#f1fa8c";
static const char drac_orange[]		= "#ffb86c";
static const char drac_red[]		= "#ff5555";
static const char drac_pink[]		= "#ff79c6";
static const char drac_grey[]		= "#44475a";
static const char drac_grey2[]		= "#343746";

static const char *colors[][3]      = {
	/*               fg				bg         border   */
	[SchemeNorm]	= { drac_fg,		drac_bg3,	drac_sel  },
	[SchemeSel]		= { drac_fg,		drac_bg,	drac_sel2 },
	[SchemeUline]	= { drac_sel3,		drac_bg3,	drac_green  }, // border color of floating windows
	[SchemeUlineA]	= { drac_sel2,		drac_bg,	drac_cyan  },
	[SchemeSymbol]	= { drac_fg,		drac_bg2,	drac_sel  },
	[SchemeTitle]	= { drac_sel2,		drac_bg,	drac_sel  },
	[SchemeCol1]	= { drac_fg,		drac_bg,	drac_sel  }, // button bar
	[SchemeCol2]	= { drac_green,		drac_bg3,	drac_sel  }, // floating win title
	[SchemeCol3]	= { drac_cyan,		drac_bg3,	drac_sel  },
	[SchemeCol4]	= { drac_fg2,		drac_bg3,	drac_sel  },
};
