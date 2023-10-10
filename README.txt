Minimal bootstrappable C compiler

This is a WIP of creating a bootstrap C compiler from scratch. It will closely
track chibicc https://github.com/rui314/chibicc . Essentially the plan is to
replay the git history from chibicc but port the compiler to a much simplified
version of C. This approach is similar to https://github.com/fosslinux/boteicc
(which is where I got the idea) but with several significant differences:

I will initially port to a subset of JS that I call the "js_to_c dialect". I
created this dialect in https://github.com/cosinusoidally/tcc_bootstrap_alt in
order to allow me to port the Tiny C Compiler to JS, and then automatically
translate it back to C. That may seem strange, but the js_to_c dialect has
several useful characteristics:

* Can be run under a JS vm (this is important for my other project "mishmashvm"
  which will eventually use the JS based version of tcc as its initial bootstrap
  compiler)
* Can be trivially translated to C using a couple of simple translation rules
* The dialect of C it generates can be built by multiple C compilers, including
  very limited compilers intended for bootstrapping. Supported C compilers are:

  * cc_x86 https://github.com/oriansj/stage0-posix-x86 (very limited compiler)
  * M2-Planet https://github.com/oriansj/m2-planet (a fleshed out version of
    cc_x86 implemented in C rather than assembly)
  * tcc https://savannah.nongnu.org/projects/tinycc (the Tiny C compiler
    originally writtent by Fabrice Bellard). I'm targeting 2 versions:
    * my "tcc_1_7" fork, which is a cut down version of a circa 2001 copy
    * the last official 0.9.27 release This is from 2017, but if they ever
      finally do a new release I might test that version too. There is
      interesting stuff in their "mob" branch, but "mob" is a complete free for
      all that anyone on the internet can push to without review. I've been
      bitten by random breakages in mob before, and I can't be bothered wasting
      my time.
  * GCC https://gcc.gnu.org/ standard C compiler on virtually all Linux distros.
    Versions I have tested are 7.3.0 from Ubuntu 18.04 and 11.4.0 from Ubuntu
    22.04. In theory most versions should work, but I use -O0 to turn off
    optimizations since GCC optimization sometimes feel like an exercise in 
    reductio ad absurdum "the language spec says we can do this, so following
    through to its logical conclusion this 'optimization' that breaks working
    code is perfectly reasonable". I say "reductio ad absurdum" but it misses
    out the bit where they realise the absurdity of what they are doing, and
    then criticise the absurdity of the specification.

What do I mean by "bootstrapping"? Bootstrapping is the process of creating
compilers that are able to compile themselves. Those compilers can then be used
to compile more complete or sophisticated implemententations (so long as those
implementations are implemented in a small enough subset of the language so that
they can be compiled via the boostrap compiler). By sucessive bootstrapping
steps it is possible to go from a simple C compiler for a small subset of C, all
the way up to highly sophisticated C compilers like GCC. But how do you compile
the initial bootstrap compiler? How small can you go. The plan with this repo is
to start with cc_x86 from https://github.com/oriansj/stage0-posix-x86 and create
a simple and understandable C compiler that can be used to build the intial step
from tcc_bootstrap_alt (which can then bootstrap up to tcc-0.9.27).

See also https://github.com/fosslinux/live-bootstrap/ which is able to go from a
<500 byte seed all the way up to GCC (and a full Linux kernel/userspace). This
process uses cc_x86, M2-Planet and tcc as intermediate steps. cc_x86 is the
earliest C compiler in live-bootstrap.
