// See LICENSE file for copyright and license details.
// vim:sw=2:ts=2:sts=2:et:cc=140
//
// TODO:
// add to man:
//
// +.B Mod1\-o
// +Select view of the window in focus. The list of tags to be displayed is matched to the window tag list.
// +.TP
//

// appearance
static const char               font[]                  = "Terminus:size=9:antialias=false:autohint=false";

static const char               normbordercolor[]       = "#080808";            // window borders color
static const char               normbgcolor[]           = "#000000";            // background color
static const char               normfgcolor[]           = "#008000";            // text color in status bar
static const char               selbordercolor[]        = "#005f00";            // active window border color
static const char               selbgcolor[]            = "#080808";            // window title/tags background color
static const char               selfgcolor[]            = "#00ff00";            // window title/tags foreground color

static const unsigned int       borderpx                = 1;                    // border pixel of windows
static const unsigned int       snap                    = 32;                   // snap pixel
static const unsigned int       systrayspacing          = 2;                    // systray spacing
static const bool               showsystray             = true;                 // False means no systray
static const bool               showbar                 = true;                 // False means no bar
static const bool               topbar                  = false;                // False means bottom bar

// layout(s)
static const float              mfact                   = 0.55;                 // factor of master area size [0.05..0.95]
static const int                nmaster                 = 1;                    // number of clients in master area
static const bool               resizehints             = false;                // True means respect size hints in tiled resizals

static const Layout layouts[] = {
// symbol       arrange function
 { "[]=",       tile            }, // idx:0  key:Mod+t                          // first entry is default
 { "><>",       NULL            }, // idx:1  key:Mod+f                          // no layout function means floating behaviour
 { "[M]",       monocle         }, // idx:2  key:Mod+m
 { "TTT",       bstack          }, // idx:3  key:Mod+s
 { "===",       bstackhoriz     }, // idx:4  key:Mod+h
 { "###",       gaplessgrid     }, // idx:5  key:Mod+g
};

// number of tags per monitor
#define TAGS    9

// Max tag length is 22 (excludes tag number with semicolon)
// If you want to change it, look at struct definition in dwm.c
static CustomTagLayout tags[][TAGS] = {
// monitor 0
// tag name,    layout idx (see layouts)
{{"1:ff",                2},
 {"2:mail/rss/chat",     3},
 {"3",                   0},
 {"4",                   0},
 {"5",                   0},
 {"6",                   0},
 {"7",                   0},
 {"8:qb",                0},
 {"9:mix",               2}},

// monitor 1
// ...
};

static const Rule rules[] = {
// class                instance        title                 role                                tag mask  isfloating  iscentered  monitor

// fixed monitor
 { "Firefox",           NULL,             NULL,               NULL,                               0,        false,      false,      0  },
 { "Navigator",         NULL,             NULL,               NULL,                               0,        false,      false,      0  },
 { "XTerm",             NULL,             "irc",              NULL,                               2,        false,      false,      0  },
 { "XTerm",             NULL,             "tox",              NULL,                               2,        false,      false,      0  },
 { "XTerm",             NULL,             "rss",              NULL,                               2,        false,      false,      0  },
 { "XTerm",             NULL,             "mail",             NULL,                               2,        false,      false,      0  },
 { "qBittorrent",       NULL,             NULL,               NULL,                               128,      false,      false,      0  },
 { "Pavucontrol",       "pavucontrol",    "Volume Control",   NULL,                               256,      false,      false,      0  },
 { "Jukebox",           "jukebox",        NULL,               "with search and lists 2",          256,      false,      false,      0  },
 { "Jukebox",           "jukebox",        "Settings",         "Pref",                             256,      true,       true,       0  },
 { "Jukebox",           "jukebox",        "Equalizer",        "Equalizer",                        256,      true,       true,       0  },

// current active monitor
 { "FTerm",             NULL,           NULL,                 NULL,                               0,        true,       true,       -1 },
 { "FTerm",             NULL,           NULL,                 NULL,                               0,        true,       true,       -1 },
 { "Gimp",              NULL,           NULL,                 NULL,                               0,        true,       true,       -1 },
 { "Lazarus",           NULL,           NULL,                 NULL,                               0,        true,       true,       -1 },
 { "floaterm",          "xterm",        NULL,                 NULL,                               0,        true,       true,       -1 },
 { "XBiff",             "xbiff",        "xbiff",              NULL,                              ~0,        true,       true,       -1 },
 { "XClock",            "xclock",       "xclock",             NULL,                              ~0,        true,       true,       -1 },
 { "XCalc",             "xcalc",        "Calculator",         NULL,                               0,        true,       true,       -1 },
 { "Xmessage",          "xmessage",     "xmessage",           NULL,                               0,        true,       true,       -1 },
 { "Ssvnc.tcl",         "ssvnc.tcl",    "SSL/SSH VNC Viewer", NULL,                               0,        true,       true,       -1 },
};

// key definitions
// Mod4Mask - Windows key, Mod1Mask - Alt
#define MODKEY Mod4Mask
// helper for spawning shell commands in the pre dwm-5.0 fashion
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// Multimedia keyboard definitions
#include <X11/XF86keysym.h>

static const char *drun_cmd[] = {
 "dmenu_run",
        "-p", "Run: ",
        "-fn", font,
        "-nb", normbgcolor,
        "-nf", normfgcolor,
        "-sb", selbgcolor,
        "-sf", selfgcolor,
        NULL,
};
static const char *pass_cmd[] = {
 "passmenu",
        "-p", "Password: ",
        "-fn", font,
        "-nb", normbgcolor,
        "-nf", normfgcolor,
        "-sb", selbgcolor,
        "-sf", selfgcolor,
        NULL
};
static const char *lock_cmd[] = { "scrlock", NULL };
static const char *term_cmd[] = { "xterm",   NULL };

// music player settings
static const char *player_play_cmd[]  = { "jukebox", "-cmd", "PlayPause", NULL };
static const char *player_stop_cmd[]  = { "jukebox", "-cmd", "Stop",      NULL };
static const char *player_prev_cmd[]  = { "jukebox", "-cmd", "PrevSong",  NULL };
static const char *player_next_cmd[]  = { "jukebox", "-cmd", "NextSong",  NULL };

#ifdef __DragonFly__
// DragonFly Mixer
static const char *mixer_vol_mute[]   = { "mixer", "vol", "0",   NULL };
static const char *mixer_vol_inc[]    = { "mixer", "vol", "+10", NULL };
static const char *mixer_vol_dec[]    = { "mixer", "vol", "-10", NULL };
#else
// ALSA mixer
static const char *master_mute_cmd[]  = { "amixer", "sset", "Master", "toggle", NULL };
static const char *master_decv_cmd[]  = { "amixer", "sset", "Master", "1-",     NULL };
static const char *master_incv_cmd[]  = { "amixer", "sset", "Master", "1+",     NULL };
#endif

// Notebooks settings
static const char *xbacklight_i_cmd[] = { "xbacklight", "-inc", "10", NULL };
static const char *xbacklight_d_cmd[] = { "xbacklight", "-dec", "10", NULL };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static Key keys[] = {
// modifier                     key                             function                argument
 { MODKEY,                      XK_r,                           spawn,                  {.v = drun_cmd}         },
 { MODKEY,                      XK_p,                           spawn,                  {.v = pass_cmd}         },

 { MODKEY,                      XK_l,                           spawn,                  {.v = lock_cmd}         },
 { MODKEY|ShiftMask,            XK_Return,                      spawn,                  {.v = term_cmd}         },

 { MODKEY,                      XK_b,                           togglebar,              {0}                     },

 { MODKEY,                      XK_n,                           nametag,                {0}                     },

 { MODKEY,                      XK_j,                           focusstack,             {.i = +1}               },
 { MODKEY,                      XK_k,                           focusstack,             {.i = -1}               },

 { MODKEY,                      XK_F1,                          focusnstack,            {.i = 1}                },
 { MODKEY,                      XK_F2,                          focusnstack,            {.i = 2}                },
 { MODKEY,                      XK_F3,                          focusnstack,            {.i = 3}                },
 { MODKEY,                      XK_F4,                          focusnstack,            {.i = 4}                },
 { MODKEY,                      XK_F5,                          focusnstack,            {.i = 5}                },
 { MODKEY,                      XK_F6,                          focusnstack,            {.i = 6}                },
 { MODKEY,                      XK_F7,                          focusnstack,            {.i = 7}                },
 { MODKEY,                      XK_F8,                          focusnstack,            {.i = 8}                },
 { MODKEY,                      XK_F9,                          focusnstack,            {.i = 9}                },

 { MODKEY,                      XK_i,                           incnmaster,             {.i = +1}               },
 { MODKEY,                      XK_d,                           incnmaster,             {.i = -1}               },
 { MODKEY|ShiftMask,            XK_h,                           setmfact,               {.f = -0.01}            },
 { MODKEY|ShiftMask,            XK_l,                           setmfact,               {.f = +0.01}            },

 { MODKEY,                      XK_Return,                      zoom,                   {0}                     },
 { MODKEY,                      XK_Tab,                         view,                   {0}                     },
 { MODKEY,                      XK_c,                           killclient,             {0}                     },
 { MODKEY,                      XK_t,                           setlayout,              {.v = &layouts[0]}      },
 { MODKEY,                      XK_f,                           setlayout,              {.v = &layouts[1]}      },
 { MODKEY,                      XK_m,                           setlayout,              {.v = &layouts[2]}      },
 { MODKEY,                      XK_s,                           setlayout,              {.v = &layouts[3]}      },
 { MODKEY,                      XK_h,                           setlayout,              {.v = &layouts[4]}      },
 { MODKEY,                      XK_g,                           setlayout,              {.v = &layouts[5]}      },
 { MODKEY,                      XK_space,                       setlayout,              {0}                     },
 { MODKEY|ShiftMask,            XK_space,                       togglefloating,         {0}                     },
 { MODKEY,                      XK_0,                           view,                   {.ui = ~0}              },
 { MODKEY|ShiftMask,            XK_0,                           tag,                    {.ui = ~0}              },
 { MODKEY,                      XK_o,                           winview,                {0},                    },
 { MODKEY|ShiftMask,            XK_f,                           togglefullscr,          {0}                     },
 { MODKEY,                      XK_comma,                       focusmon,               {.i = -1}               },
 { MODKEY,                      XK_period,                      focusmon,               {.i = +1}               },
 { MODKEY|ShiftMask,            XK_comma,                       tagmon,                 {.i = -1}               },
 { MODKEY|ShiftMask,            XK_period,                      tagmon,                 {.i = +1}               },

 { MODKEY|ShiftMask,            XK_q,                           quit,                   {0}                     },

#define TAGKEYS(KEY,TAG) \
 { MODKEY,                      KEY,                            view,                   {.ui = 1 << TAG}        }, \
 { MODKEY|ControlMask,          KEY,                            toggleview,             {.ui = 1 << TAG}        }, \
 { MODKEY|ShiftMask,            KEY,                            tag,                    {.ui = 1 << TAG}        }, \
 { MODKEY|ControlMask|ShiftMask,KEY,                            toggletag,              {.ui = 1 << TAG}        },

        TAGKEYS(                XK_1,                                                                   0)
        TAGKEYS(                XK_2,                                                                   1)
        TAGKEYS(                XK_3,                                                                   2)
        TAGKEYS(                XK_4,                                                                   3)
        TAGKEYS(                XK_5,                                                                   4)
        TAGKEYS(                XK_6,                                                                   5)
        TAGKEYS(                XK_7,                                                                   6)
        TAGKEYS(                XK_8,                                                                   7)
        TAGKEYS(                XK_9,                                                                   8)

// Multimedia keyboard shortcuts
// Media player
 { 0,                           XF86XK_AudioPlay,               spawn,                  {.v = player_play_cmd}  },
 { 0,                           XF86XK_AudioStop,               spawn,                  {.v = player_stop_cmd}  },
 { 0,                           XF86XK_AudioPrev,               spawn,                  {.v = player_prev_cmd}  },
 { 0,                           XF86XK_AudioNext,               spawn,                  {.v = player_next_cmd}  },
#ifdef __DragonFly__
// DragonFly Mixer
 { 0,                           XF86XK_AudioMute,               spawn,                  {.v = master_mute_cmd}  },
 { 0,                           XF86XK_AudioLowerVolume,        spawn,                  {.v = mixer_vol_dec}    },
 { 0,                           XF86XK_AudioRaiseVolume,        spawn,                  {.v = mixer_vol_inc}    },
#else
// ALSA Linux Mixer
 { 0,                           XF86XK_AudioMute,               spawn,                  {.v = master_mute_cmd}  },
 { 0,                           XF86XK_AudioLowerVolume,        spawn,                  {.v = master_decv_cmd}  },
 { 0,                           XF86XK_AudioRaiseVolume,        spawn,                  {.v = master_incv_cmd}  },
#endif
// Brightness
 { 0,                           XF86XK_MonBrightnessUp,         spawn,                  {.v = xbacklight_i_cmd} },
 { 0,                           XF86XK_MonBrightnessDown,       spawn,                  {.v = xbacklight_d_cmd} },
};

// button definitions
// click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin
static Button buttons[] = {
// click                event mask      button          function                argument
 { ClkLtSymbol,         0,              Button1,        setlayout,              {0}                     },
 { ClkLtSymbol,         0,              Button3,        setlayout,              {.v = &layouts[2]}      },
#ifdef WINTITLE
 { ClkWinTitle,         0,              Button2,        zoom,                   {0}                     },
#endif
 { ClkStatusText,       0,              Button2,        spawn,                  {.v = term_cmd}         },
 { ClkClientWin,        MODKEY,         Button1,        movemouse,              {0}                     },
 { ClkClientWin,        MODKEY,         Button2,        togglefloating,         {0}                     },
 { ClkClientWin,        MODKEY,         Button3,        resizemouse,            {0}                     },
 { ClkTagBar,           0,              Button1,        view,                   {0}                     },
 { ClkTagBar,           0,              Button3,        toggleview,             {0}                     },
 { ClkTagBar,           MODKEY,         Button1,        tag,                    {0}                     },
 { ClkTagBar,           MODKEY,         Button3,        toggletag,              {0}                     },
};

// End of file
