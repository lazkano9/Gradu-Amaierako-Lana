#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/GAL_V4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/GAL_V4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../CN.c ../LCD.c ../MAIN.c ../i2c_funtzioak.c ../kalk_bihurketak.c ../memoria.c ../mpu9250.c ../oscilator.c ../timer_denbora.c ../globals.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/CN.o ${OBJECTDIR}/_ext/1472/LCD.o ${OBJECTDIR}/_ext/1472/MAIN.o ${OBJECTDIR}/_ext/1472/i2c_funtzioak.o ${OBJECTDIR}/_ext/1472/kalk_bihurketak.o ${OBJECTDIR}/_ext/1472/memoria.o ${OBJECTDIR}/_ext/1472/mpu9250.o ${OBJECTDIR}/_ext/1472/oscilator.o ${OBJECTDIR}/_ext/1472/timer_denbora.o ${OBJECTDIR}/_ext/1472/globals.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/CN.o.d ${OBJECTDIR}/_ext/1472/LCD.o.d ${OBJECTDIR}/_ext/1472/MAIN.o.d ${OBJECTDIR}/_ext/1472/i2c_funtzioak.o.d ${OBJECTDIR}/_ext/1472/kalk_bihurketak.o.d ${OBJECTDIR}/_ext/1472/memoria.o.d ${OBJECTDIR}/_ext/1472/mpu9250.o.d ${OBJECTDIR}/_ext/1472/oscilator.o.d ${OBJECTDIR}/_ext/1472/timer_denbora.o.d ${OBJECTDIR}/_ext/1472/globals.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/CN.o ${OBJECTDIR}/_ext/1472/LCD.o ${OBJECTDIR}/_ext/1472/MAIN.o ${OBJECTDIR}/_ext/1472/i2c_funtzioak.o ${OBJECTDIR}/_ext/1472/kalk_bihurketak.o ${OBJECTDIR}/_ext/1472/memoria.o ${OBJECTDIR}/_ext/1472/mpu9250.o ${OBJECTDIR}/_ext/1472/oscilator.o ${OBJECTDIR}/_ext/1472/timer_denbora.o ${OBJECTDIR}/_ext/1472/globals.o

# Source Files
SOURCEFILES=../CN.c ../LCD.c ../MAIN.c ../i2c_funtzioak.c ../kalk_bihurketak.c ../memoria.c ../mpu9250.c ../oscilator.c ../timer_denbora.c ../globals.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/GAL_V4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ256GP610A
MP_LINKER_FILE_OPTION=,--script=p24HJ256GP610A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/CN.o: ../CN.c  .generated_files/flags/default/5b7352f684155ad9085795c798340a784bba837a .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CN.c  -o ${OBJECTDIR}/_ext/1472/CN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/CN.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/LCD.o: ../LCD.c  .generated_files/flags/default/1e581501c07c9356412198d2f559edcfa9bb4379 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../LCD.c  -o ${OBJECTDIR}/_ext/1472/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/LCD.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/MAIN.o: ../MAIN.c  .generated_files/flags/default/4614f1d48e28fb3baba3868587ae610a3545a654 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MAIN.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MAIN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MAIN.c  -o ${OBJECTDIR}/_ext/1472/MAIN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/MAIN.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/i2c_funtzioak.o: ../i2c_funtzioak.c  .generated_files/flags/default/5e2096ead3dcd76eaa598e88a91409afcfe42da7 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c_funtzioak.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c_funtzioak.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../i2c_funtzioak.c  -o ${OBJECTDIR}/_ext/1472/i2c_funtzioak.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/i2c_funtzioak.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/kalk_bihurketak.o: ../kalk_bihurketak.c  .generated_files/flags/default/3c779ffcc2eba17c86999c034a80c33bc5dfb381 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/kalk_bihurketak.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/kalk_bihurketak.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../kalk_bihurketak.c  -o ${OBJECTDIR}/_ext/1472/kalk_bihurketak.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/kalk_bihurketak.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/memoria.o: ../memoria.c  .generated_files/flags/default/35d076a91149addc868971eb69e00d0226d19322 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../memoria.c  -o ${OBJECTDIR}/_ext/1472/memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/memoria.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/mpu9250.o: ../mpu9250.c  .generated_files/flags/default/5ce9b90129e8a89b1ed62cb0b61af11afc644a07 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/mpu9250.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/mpu9250.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mpu9250.c  -o ${OBJECTDIR}/_ext/1472/mpu9250.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/mpu9250.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/oscilator.o: ../oscilator.c  .generated_files/flags/default/fe1c8763498ff46b7b1475b0e8c571e99e0e4fe2 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../oscilator.c  -o ${OBJECTDIR}/_ext/1472/oscilator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/oscilator.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/timer_denbora.o: ../timer_denbora.c  .generated_files/flags/default/b18d9fcfdd95677c768b8c288f5f60c5e7f814ba .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/timer_denbora.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/timer_denbora.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../timer_denbora.c  -o ${OBJECTDIR}/_ext/1472/timer_denbora.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/timer_denbora.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/globals.o: ../globals.c  .generated_files/flags/default/6bffab9113295e57ab6d78c6d4db894ba6ab8add .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/globals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/globals.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../globals.c  -o ${OBJECTDIR}/_ext/1472/globals.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/globals.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/1472/CN.o: ../CN.c  .generated_files/flags/default/104e5cdf51dd18548eed3410c2786de79170779a .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/CN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../CN.c  -o ${OBJECTDIR}/_ext/1472/CN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/CN.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/LCD.o: ../LCD.c  .generated_files/flags/default/59c66dfb16725a85a4a2214a72027adf630f77da .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../LCD.c  -o ${OBJECTDIR}/_ext/1472/LCD.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/LCD.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/MAIN.o: ../MAIN.c  .generated_files/flags/default/ffa4bb9f71124e1ba681dfa13cb7fb71695f27ac .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MAIN.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MAIN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MAIN.c  -o ${OBJECTDIR}/_ext/1472/MAIN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/MAIN.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/i2c_funtzioak.o: ../i2c_funtzioak.c  .generated_files/flags/default/4b26d46081d00fe287a3087eda520210b0235a34 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c_funtzioak.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/i2c_funtzioak.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../i2c_funtzioak.c  -o ${OBJECTDIR}/_ext/1472/i2c_funtzioak.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/i2c_funtzioak.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/kalk_bihurketak.o: ../kalk_bihurketak.c  .generated_files/flags/default/8e5d335fa59ae0c264a3e6e9aada7550ead993ce .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/kalk_bihurketak.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/kalk_bihurketak.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../kalk_bihurketak.c  -o ${OBJECTDIR}/_ext/1472/kalk_bihurketak.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/kalk_bihurketak.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/memoria.o: ../memoria.c  .generated_files/flags/default/c3a1a4c5fe151de29999409509a0e4999d338a8a .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/memoria.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../memoria.c  -o ${OBJECTDIR}/_ext/1472/memoria.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/memoria.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/mpu9250.o: ../mpu9250.c  .generated_files/flags/default/34ebc723cf5fd9d8248d436bb61dec427e1b3056 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/mpu9250.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/mpu9250.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../mpu9250.c  -o ${OBJECTDIR}/_ext/1472/mpu9250.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/mpu9250.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/oscilator.o: ../oscilator.c  .generated_files/flags/default/2c89ffc80d45f51562e1e72a65de1e75be9a9c09 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/oscilator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../oscilator.c  -o ${OBJECTDIR}/_ext/1472/oscilator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/oscilator.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/timer_denbora.o: ../timer_denbora.c  .generated_files/flags/default/7a2491f3d757941b70ecdf8ce34060feffd4d25 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/timer_denbora.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/timer_denbora.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../timer_denbora.c  -o ${OBJECTDIR}/_ext/1472/timer_denbora.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/timer_denbora.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/globals.o: ../globals.c  .generated_files/flags/default/5992fcf08b0560b44153f66474101c6e47921926 .generated_files/flags/default/74d464f3899599845d713a1d015fd0bf2695bd19
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/globals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/globals.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../globals.c  -o ${OBJECTDIR}/_ext/1472/globals.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/globals.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/GAL_V4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/GAL_V4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/GAL_V4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/GAL_V4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/GAL_V4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
