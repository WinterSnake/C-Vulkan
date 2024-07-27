# -Project
project('vulkan', 'c', version: '1.0.0', default_options: {'warning_level': '2'})

# -Dependencies
depglfw = dependency('glfw3')

# -Output
executable('vulkan', sources: ['./src/main.c'], include_directories: './include', dependencies: [depglfw])
