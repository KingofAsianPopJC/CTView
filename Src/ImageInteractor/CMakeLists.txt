CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT (ImageInteractor)

FIND_PACKAGE(VTK REQUIRED)
IF(VTK_FOUND)
    INCLUDE(${VTK_USE_FILE})
ELSE ()
    MASSAGE(FATAL_ERROR "Cannnot build without ITK. Please set VTK_DIR.")
ENDIF()

FIND_PACKAGE(ITK REQUIRED)
IF(ITK_FOUND)
    INCLUDE(${ITK_USE_FILE})
ELSE ()
    MASSAGE(FATAL_ERROR "Cannnot build without ITK. Please set ITK_DIR.")
ENDIF()

IF(ITKVtkGlue_LOADED)
   FIND_PACKAGE(VTK REQUIRED)
   INCLUDE(${VTK_USE_FILE})
ELSE()
   MASSAGE(FATAL_ERROR "You need to select ITKVtkGlue when compile ITK.")
ENDIF()

SET(ImageInteractor_SOURCES ImageInteractor.cpp)
SET(ImageInteractor_HEADERS ImageInteractor.h)

ADD_LIBRARY(ImageInteractor  ${ImageInteractor_SOURCES}
                          ${ImageInteractor_HEADERS}
		    )
			
TARGET_LINK_LIBRARIES(ImageInteractor ${ITK_LIBRARIES} ${VTK_LIBRARIES})