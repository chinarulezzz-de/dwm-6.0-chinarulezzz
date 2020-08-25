# dwm version
VERSION=	6.0

# Customize below to fit your system

# paths
PREFIX=		/usr/local
MANPREFIX=	${PREFIX}/share/man

# includes
BASEINC=	-I${.CURDIR}
BASEINC+=	-I/usr/include
BASEINC+=	-I/usr/local/include
X11INC=		-I/usr/include/X11
X11INC+=	-I/usr/local/include/X11
FREETYPEINC=	-I/usr/include/freetype2
FREETYPEINC+=	-I/usr/local/include/freetype2

# libs
BASELIB=	-L/usr/lib
BASELIB+=	-L/usr/local/lib
X11LIB=		-L/usr/lib/X11
X11LIB+=	-L/usr/local/lib/X11


# per-window keyboard layout
PWKL=		-DPWKL

# Xinerama
XINERAMALIBS=	-lXinerama
XINERAMAFLAGS=	-DXINERAMA

INCS=		${BASEINC} ${X11INC} ${FREETYPEINC}
LIBS=		${BASELIB} ${X11LIB} -lc -lX11 -lXft ${XINERAMALIBS}

# flags
#CPPFLAGS=	-D_POSIX_C_SOURCE=2 -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS} ${PWKL}
CPPFLAGS=	-D_DEFAULT_SOURCE -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS} ${PWKL}
CFLAGS=		-std=c99 -pedantic -Wall -Wextra -Os -Wformat ${INCS} ${CPPFLAGS}
LDFLAGS=	-s ${LIBS}

# Solaris
#CFLAGS=	-fast ${INCS} -DVERSION=\"${VERSION}\"
#LDFLAGS=	${LIBS}

# compiler and linker
CC?=		cc
