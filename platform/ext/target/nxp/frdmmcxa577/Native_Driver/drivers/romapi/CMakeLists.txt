if (CONFIG_MCUX_COMPONENT_driver.romapi)
    mcux_component_version(2.0.0)

    mcux_add_source(
        SOURCES
            ./fsl_romapi.h
            ./fsl_romapi_tree.h
    )

    mcux_add_include(INCLUDES .)
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_flashiap)
    mcux_component_version(2.0.0)

    mcux_add_source(
        SOURCES
            ./flash/fsl_flash.c
            ./flash/fsl_flash.h
            ./flash/fsl_flexspi_nor_flash.h
            ./flash/fsl_lpspi_flash.h
            ./fsl_romapi_tree.h
    )

    mcux_add_include(INCLUDES ./flash ./)
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_nboot)
    mcux_component_version(2.0.0)

    mcux_add_source(
        SOURCES 
            ./nboot/fsl_nboot.c
            ./nboot/fsl_nboot_hal.h
            ./nboot/fsl_nboot.h
            ./fsl_romapi_tree.h)

    mcux_add_include(INCLUDES ./nboot ./)
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_runbootloader)
    mcux_component_version(2.0.0)

    mcux_add_source(
        SOURCES
            ./runbootloader/fsl_runbootloader.c
            ./runbootloader/fsl_runbootloader.h
            ./fsl_romapi_tree.h
    )

    mcux_add_include( INCLUDES ./runbootloader ./)
endif()

if (CONFIG_MCUX_COMPONENT_driver.romapi_kbapi)
    mcux_component_version(2.0.0)

    mcux_add_source(
        SOURCES
            ./kbapi/fsl_kbapi.h
            ./kbapi/fsl_kbapi.c
            ./fsl_romapi_tree.h
    )

    mcux_add_include( INCLUDES ./kbapi ./)
endif()