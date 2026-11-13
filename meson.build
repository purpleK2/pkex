project('libpkex', 'c', version: '0.1.0')

pkex_include = include_directories('include')
libpkex_dep = declare_dependency(
  include_directories: pkex_include
)

meson.override_dependency('libpkex', libpkex_dep)
