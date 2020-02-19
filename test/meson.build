project('temper-test', 'cpp',
	version : '0.1.0',
	license : 'GPL3',
	meson_version : '0.53.1',
	default_options : ['warning_level=3', 'buildtype=debug'])

subdir('src')

executable('temper-test', sources)

run_target('check',
  command : 'scripts/run_tests.sh')
