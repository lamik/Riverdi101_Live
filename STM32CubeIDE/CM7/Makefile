# Helper macros to convert spaces into question marks and back again
e :=
sp := $(e) $(e)
qs = $(subst ?,$(sp),$1)
sq = $(subst $(sp),?,$1)

# Get name of this Makefile (avoid getting word 0 and a starting space)
makefile_name := $(wordlist 1,1000,$(MAKEFILE_LIST))

# Get path where the Application is
application_path := $(call qs,$(abspath $(call sq,$(makefile_path)..)))

stm32cube_programmer_path := STMicroelectronics/STM32Cube/STM32CubeProgrammer/bin
stm32cube_programmer_filename := STM32_Programmer_CLI.exe
stm32cube_programmer_filepath := $(stm32cube_programmer_path)/$(stm32cube_programmer_filename)
stm32cube_loader_relative_path := ExternalLoader/$(stldr)
stm32cube_loader := $(stm32cube_programmer_path)/$(stm32cube_loader_relative_path)

program_files_win32 = /c/Program Files (x86)
program_files_win64 = /c/Program Files

program_files_path := $(program_files_win64)

# fall back to 32bit program files if 64bit is not found
ifeq ("$(shell find "$(program_files_win64)/$(stm32cube_programmer_filepath)" 2> nul )","")
program_files_path := $(program_files_win32)
endif

st_stm32cube_programmer_path := $(program_files_path)/$(stm32cube_programmer_path)
st_stm32cube_programmer_filepath := $(program_files_path)/$(stm32cube_programmer_filepath)
st_stm32cube_external_loader := $(program_files_path)/$(stm32cube_loader)


# Get path of this Makefile
makefile_path := $(call qs,$(dir $(call sq,$(abspath $(call sq,$(makefile_name))))))

.PHONY: all clean assets flash intflash


flash intflash: all

	@cd "$(st_stm32cube_programmer_path)" && ./$(stm32cube_programmer_filename) -c port=SWD -vb 3 -d $(makefile_path)/Debug/flash.bin 0x08000000 -hardRst 
	@cd "$(st_stm32cube_programmer_path)" && ./$(stm32cube_programmer_filename) -c port=SWD -vb 3 -d $(makefile_path)/Debug/qspi.bin 0x90000000 -hardRst -el $(makefile_path)/Middlewares/Stldr/STM32H_IPS_Riverdi_CM7_v3.stldr
	
.PHONY: _all_ _clean_ _assets_ _flash_ _intflash_ generate_assets build_executable

_flash_: _intflash_

