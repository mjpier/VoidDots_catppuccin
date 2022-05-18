/* user and group to drop privileges to */
static const char *user  = "mjpier";
static const char *group = "mjpier";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#000000",   /* after initialization */
	[INPUT] =  "#1d2021",   /* during input */
	[FAILED] = "#cc241d",   /* wrong password */
};

/* lock screen opacity */
static const float alpha = 0.6;

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* default message */
static const char * message = "Enter password to unlock";

/* text color */
static const char * text_color = "#ebdbb2";

/* text size (must be a valid size) */
/* static const char * text_size = "9x15"; */
static const char * font_name = "Inconsolata:size=28:antialias=true:autohint=true";

