[![Release version](https://img.shields.io/github/v/release/sramsay/temper?sort=semver)](https://img.shields.io/github/v/release/sramsay/temper?sort=semver)
![C/C++ CI](https://github.com/sramsay/temper/workflows/C/C++%20CI/badge.svg)
[![Build Status](https://travis-ci.org/sramsay/temper.svg?branch=master)](https://travis-ci.org/sramsay/temper)
[![Build Status](https://circleci.com/gh/sramsay/temper.svg?style=svg)](https://app.circleci.com/github/sramsay/temper/pipelines?branch=master)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/20428/badge.svg)](https://scan.coverity.com/projects/sramsay-temper)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/fafa33d720a84726838a83c60be1e183)](https://app.codacy.com/manual/sramsay/temper?utm_source=github.com&utm_medium=referral&utm_content=sramsay/temper&utm_campaign=Badge_Grade_Settings)
[![Total alerts](https://img.shields.io/lgtm/alerts/g/sramsay/temper.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/sramsay/temper/alerts/)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/sramsay/temper.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/sramsay/temper/context:cpp)
[![CII Best Practices](https://bestpractices.coreinfrastructure.org/projects/3715/badge)](https://bestpractices.coreinfrastructure.org/projects/3715)
[![Percentage of issues still open](http://isitmaintained.com/badge/open/sramsay/temper.svg)](http://isitmaintained.com/project/sramsay/temper "Percentage of issues still open")
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

<!-- [![Average time to resolve an issue](http://isitmaintained.com/badge/resolution/sramsay/temper.svg)](http://isitmaintained.com/project/sramsay/temper "Average time to resolve an issue") -->

# temper

## Frequently Unasked Questions

### Is this the program I'm looking for?

Probably not.

### What does this program do?

It's a command-line program for UNIX-like systems that converts from Fahrenheit to Celsius and vice versa.  So if you type:

	temper 23

It will give you:

	23.0°F is -5.0°C
	23.0°C is 73.4°F

You can also adjust the precision with the --precision switch, so that:

	$ temper --precision=3 -320.4

gives you:

	-320.400°F is -195.778°C
	-320.400°C is -544.720°F

The default precision is 1.

### Doesn't [GNU units](https://www.gnu.org/software/units/) already do that?

Yes.

### So why did you write this thing?

As an American, I am completely illiterate when it comes to the metric system.  It often happens, though, that I'm in a chatroom or something and one of my friends (who is living in some exotic locale like Ottawa) will say, "It's -4 degrees outside!"  Which sounds insanely cold to me.  But armed with `temper`, I can say, "Cry me a river.  That's not that cold."

### How do I compile this program?

Go grab [the latest release](https://github.com/sramsay/temper/releases).  Then it's the usual thing.  Something like:

	$ tar -xvzf temper-X.X.X..tar.gz
	$ cd temper-X.X.X
	$ ./configure
	$ make
	$ sudo make install

If you're a developer, you can clone this repository, run `autoreconf -i`, etc.

### So let me get this straight.  You wrote over a hundred lines of code in C to do something this stupid?

Yes.  I mostly use this project to play around with different build tools, linters, and continuous integration systems before I recklessly incorporate them into larger projects. 

And this particular problem is actually trickier than it looks, because when you type:

	$ temper -28

on the command line, UNIX-like systems assume that you must be trying to pass the `temper` program some kind of weird option (maybe the `-2` and `-8` options smashed together?).  Getting around that without exotic dependencies requires . . . hacking a solution.

Oh, and temper proved very useful when building [nowa](https://github.com/sramsay/nowa), which is a much more interesting and useful program.

### Couldn't you have written this in, like, one line of Ruby/Python/JavaScript with no dependencies?

Probably.

### Couldn't you have written an immaculately pure, provably correct version of this in Idris/Haskell/Coq?

Probably.

### Shouldn't everything be written in Rust?

Probably not.

### Why not do Kelvin?!

How long must I endure [you people](https://units.fandom.com/wiki/Kelvin)?

Yeah, it'd probably be cool.  On the other hand, my friends were all humanities majors, so when they say, "It's 10 degrees!" they are definitely not talking about some substance being miraculously held at -263.15&deg;C.  

And why stop there?  What about the Rankine scale?  Or Isaac Newton's scale (devised in 1701) by which one may speak of the *Calor aeris hyberni ubi aqua incipit gelu rigescere* ("the heat of air in winter at which water begins to freeze").  My humanities friends are, after all, way better at Latin.

I don't know.  Maybe version 2.

### You sound like a jerk.  Are you some kind of imperial-system zealot or something like that?

Nah, I think the metric system is way more rational, and it's the system used by most people the world over.  I wish we (Americans, Libyans, Belizeans, and Myanmars) would switch.  There's perhaps some hope for those last three, but the first seem curiously intractable on this point.

### Info

[Commits by Stephen Ramsay](https://github/sramsay/temper/commits) and [releases](https://github/sramsay/temper/releases) are signed with this [PGP Key](https://keybase.io/sramsay/pgp_keys.asc?fingerprint=ca1423bdcd55d15f35acc07a61fbe427138e5b2b).

Last Modified: Wed Dec 02 10:59:49 CST 2020
