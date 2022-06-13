STM32_Programmer_CLI.exe -c port=swd -e all 
STM32_Programmer_CLI.exe -c port=swd -e all -el "C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\ExternalLoader\STM32H_IPS_QSPI_Loader_CM7_M_64.stldr"
STM32_Programmer_CLI.exe -c port=swd -w "D:\TouchGFX_Workspace_4_18_1\Riverdi10STM32H7\RiverdiTutorial\STM32CubeIDE\CM7\Debug\flash.bin" 0x08000000
STM32_Programmer_CLI.exe -c port=swd -w "D:\TouchGFX_Workspace_4_18_1\Riverdi10STM32H7\RiverdiTutorial\STM32CubeIDE\CM4\Debug\Riverdi_101STM32H7_CM4.bin" 0x08100000
STM32_Programmer_CLI.exe -c port=swd -w "D:\TouchGFX_Workspace_4_18_1\Riverdi10STM32H7\RiverdiTutorial\STM32CubeIDE\CM7\Debug\qspi.bin" 0x90000000 -el "C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin\ExternalLoader\STM32H_IPS_QSPI_Loader_CM7_M_64.stldr"
STM32_Programmer_CLI.exe -c port=swd -hardRst

