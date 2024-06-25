################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../icuasw_mmesp_project.cpp 

CPP_DEPS += \
./icuasw_mmesp_project.d 

OBJS += \
./icuasw_mmesp_project.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	sparc-rtems-g++ -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/config/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/components/ccepdmanager/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/swpackages/emu_sc_channel_drv_slib_head/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/components/cctm_channelctrl/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/components/icuasw/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/components/rccbkgtcexec/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/components/rcchk_fdirmng/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/swpackages/icuasw_pus_services_slib_head/include/public" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/swinterfaces/leon3_hw_irqs/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/swinterfaces/can_queue/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/swinterfaces/pi_free_can_drv/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/swinterfaces/leon3_occan_drv/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/dataclasses/CDEventList/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/dataclasses/CDRecovAction/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/dataclasses/CDSensorTMBufferStatus/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/dataclasses/CDTCDescriptor/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/dataclasses/CDTMList/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/dataclasses/CDTMMemory/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/edroom_glue/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/edroombp/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/swinterfaces/datapool_mng_iface_v1/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/swinterfaces/icuasw_pus_services_iface_v1/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/swinterfaces/sc_channel_drv_iface_v1/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/edroomsl/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/edroomsl_types/include" -I"/home/atcsol/eclipse-workspace/asw_emu_tc_can_board1_sw_oscar/rtems_osswr/include" -O0 -g3 -Wall -c -fmessage-length=0 -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./icuasw_mmesp_project.d ./icuasw_mmesp_project.o

.PHONY: clean--2e-

