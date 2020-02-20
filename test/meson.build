project('temper-test', 'cpp',
	version : '0.1.0',
	license : 'GPL3',
	meson_version : '0.53.1',
	default_options : ['warning_level=3', 'buildtype=debug', 'optimization=0'])

subdir('src')

# One of these days I'll get coverage to work on MacOS
#executable('temper-test', sources, cpp_args: ['-fprofile-arcs', '-ftest-coverage'])

executable('temper-test', sources)

run_target('check',
  command : 'scripts/run_tests.sh')
