project('temper', 'cpp',
	version : '1.0.4',
	license : 'GPL3',
	meson_version : '>= 0.53',
	default_options : ['warning_level=3', 'buildtype=release', 'cpp_std=c++17'])

subdir('src')

boost = dependency('boost', modules : ['system', 'program_options', 'filesystem'])

executable('temper', sources, install : true, dependencies : [boost])

run_target('format',
	command : ['clang-format', '-i', '-style=google', '-verbose', sources, headers])

run_target('cloc',
	command : ['cloc', '--exclude-ext=json', '--exclude-list-file=.clocignore', sources])

configure_file(input : '.clang-tidy',
							 output : '.clang-tidy',
							 copy: true)

run_target('tidy',
	command : ['clang-tidy', '-p', '.', sources, '--', '-march=native',  '-I/usr/local/include', '-L/usr/local/lib', '-L/usr/local/opt/llvm/lib', '-Wl,-rpath,/usr/local/opt/llvm/lib', '>', 'errors'])
