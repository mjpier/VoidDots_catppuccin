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


/* Arc Dark */
static const char arc_bg[]			= "#282c34";
static const char arc_bg2[]       	= "#323843";
static const char arc_bg3[]       	= "#404552";
static const char arc_fg[]       	= "#e7e8eb";
static const char arc_fg2[]       	= "#ffffff";
static const char arc_blue[]        = "#5294e2";
static const char arc_blue2[]       = "#6ba4e7";


/* Dracula */
static const char drac_bg[] 		= "#282a36";
static const char drac_bg3[] 		= "#1e1f29";
static const char drac_sel[] 		= "#6272a4";
static const char drac_sel2[]		= "#bd93f9";
static const char drac_sel3[]		= "#383a59";
static const char drac_fg[] 		= "#f8f8f2";
static const char drac_green[]		= "#50fa7b";
static const char drac_cyan[]		= "#8be9fd";
static const char drac_grey[]		= "#44475a";


/* Material Palenight */
static const char pn_bg[]			= "#292D3E";
static const char pn_bg2[]      	= "#717CB4";
static const char pn_bg4[]      	= "#1c1f2b";
static const char pn_bg3[]      	= "#444267";
static const char pn_blue[]     	= "#82aaff";
static const char pn_purple[]   	= "#c792ea";
static const char pn_green[]		= "#c3e88d";
static const char pn_cyan[]			= "#89ddff";
static const char pn_green2[]   	= "#80cbc4";
static const char pn_fg[]       	= "#eeffff";


/* Gruvbox dark */
static const char gb_bg[] 			= "#1d2021";
static const char gb_bg2[] 			= "#282828";
static const char gb_bg3[] 			= "#3c3836";
static const char gb_sel[] 			= "#fabd2f";
static const char gb_sel2[]			= "#d79921";
static const char gb_fg[] 			= "#fbf1c7";
static const char gb_fg2[] 			= "#a89984";


/* One dark */
static const char one_bg[]			= "#282c34";
static const char one_bg2[]			= "#404552";
static const char one_fg[]			= "#abb2bf";
static const char one_blue[]		= "#61afef";
static const char one_green[]		= "#98c379";




static const char *colors[][3]      = {
	/*               fg         bg         border   */
	/* Nord */
	// [SchemeNorm] = { nord_fg2,  nord_bg,   nord_bg2   },
	// [SchemeSel]  = { nord_bg,	nord_blue, nord_blue  },

	/* Dracula */
	[SchemeNorm] = { drac_fg,   drac_bg3,	drac_sel  },
	[SchemeSel]  = { drac_sel2, drac_bg,	drac_sel2  },
	
	/* Arc Dark */
	// [SchemeNorm] = { arc_fg,   arc_bg2,    arc_bg3 },
	// [SchemeSel]  = { arc_fg,   arc_blue,  arc_blue },
	
	/* Material Palenight */
	// [SchemeNorm] = { pn_fg,		pn_bg,	pn_bg2 },
	// [SchemeSel]  = { pn_blue,	pn_bg,  pn_blue },
	
	/* Gruvbox dark */
	// [SchemeNorm] = { gb_fg,   	gb_bg2,   	gb_bg3   },
	// [SchemeSel]  = { gb_bg,   	gb_fg2, 	gb_fg2   },
	
	/* One dark */
	// [SchemeNorm]	= { one_fg,	  one_bg,	one_bg2 },
	// [SchemeSel]		= {one_blue,   one_bg,	one_blue },
};
