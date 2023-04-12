cmake_minimum_required( VERSION 3.24 )
project( LCD1602 )

set( CMAKE_CXX_STANDARD 14 )

include_directories( .
		"C:/Users/Adam/AppData/Local/Arduino15/libraries/LiquidCrystal/src"
		C:/Users/Adam/AppData/Local/Arduino15/libraries/LiquidCrystal/src
		)

add_executable( LCD1602
		LCD1602.ino )

set_target_properties( LCD1602 PROPERTIES LINKER_LANGUAGE CXX )
