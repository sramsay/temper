project('temper', 'c',
	version : '0.1.0',
	license : 'GPL3',
	meson_version : '>= 0.49',
	default_options : ['warning_level=3', 'buildtype=release'])

subdir('src')

executable('temper', sources, install : true)

run_target('format',
	command : ['clang-format', '-i', '-style=google', '-verbose', sources, headers])

run_target('cloc',
	command : ['cloc', '--exclude-ext=json', '--exclude-list-file=.clocignore', sources])

configure_file(input : '.clang-tidy',
							 output : '.clang-tidy',
							 copy: true)

run_target('tidy',
  command : ['clang-tidy', '-p', '.', sources, '--', '-std=c18', '-march=native',  '-I/usr/local/include', '-L/usr/local/lib', '-L/usr/local/opt/llvm/lib', '-Wl,-rpath,/usr/local/opt/llvm/lib', '>', 'errors'])

run_target('iwyu',
	command : ['iwyu_tool.py', '-o', 'clang', '-j', '9', '-p', 'build', sources])
