################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1020/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/bin/armcl" -mv4 --code_state=32 -me --include_path="/Users/rosatorres/Documents/Github_files/HEC_2_senior_design/Firmware/display_Lcd" --include_path="/Users/rosatorres/Documents/Github_files/HEC_2_senior_design/Firmware/MSP430fr5994_MCU/Includes" --include_path="/Users/rosatorres/Documents/Github_files/HEC_2_senior_design/Firmware/MSP430fr5994_MCU" --include_path="/Applications/ti/ccs1020/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/include" --include_path="/Users/rosatorres/Documents/Github_files/HEC_2_senior_design/Firmware/display_Lcd/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


