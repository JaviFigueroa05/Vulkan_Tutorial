file(GLOB SHADERS *.vert *.frag *.comp *.geom *.tesc *.tese *.mesh *.task *.rgen *.rchit *.rmiss)

foreach(SHADER IN LISTS SHADERS)
    get_filename_component(FILENAME ${SHADER} NAME)
    add_custom_command(OUTPUT ${FILENAME}.spv
        COMMAND glslc ${SHADER} -o ${FILENAME}.spv
        DEPENDS ${SHADER}
        COMMENT "Compiling ${FILENAME}")
list(APPEND SPV_SHADERS ${FILENAME}.spv)
endForeach()

add_custom_target(shaders ALL DEPENDS ${SPV_SHADERS})