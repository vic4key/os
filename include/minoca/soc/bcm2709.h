/*++

Copyright (c) 2015 Minoca Corp. All Rights Reserved

Module Name:

    bcm2709.h

Abstract:

    This header contains definitions for Broadcom 2709 System on Chip family.

Author:

    Chris Stevens 7-Jan-2015

--*/

//
// ------------------------------------------------------------------- Includes
//

//
// --------------------------------------------------------------------- Macros
//

#define BCM2709_MAILBOX_CHECK_TAG_LENGTH(_TagLength, _ExpectedLength) \
    ((((_TagLength) & BCM2709_MAILBOX_TAG_LENGTH_RESPONSE) != 0) &&   \
     (((_TagLength) & ~BCM2709_MAILBOX_TAG_LENGTH_RESPONSE) ==        \
      (_ExpectedLength)))

//
// ---------------------------------------------------------------- Definitions
//

//
// Define the offsets from the platform base for various BCM2709 components
// and their associated sizes, if necessary. The platform base is define
// specifically for each chip in the BCM2709 family.
//

#define BCM2709_SYSTEM_TIMER_OFFSET 0x00003000
#define BCM2709_INTERRUPT_OFFSET    0x0000B200
#define BCM2709_ARM_TIMER_OFFSET    0x0000B400
#define BCM2709_MAILBOX_OFFSET      0x0000B880
#define BCM2709_PRM_OFFSET          0x00100000
#define BCM2709_PRM_SIZE            0x1000
#define BCM2709_UART_OFFSET         0x00201000
#define BCM2709_EMMC_OFFSET         0x00300000

//
// Define the flags for the basic interrupts.
//

#define BCM2709_INTERRUPT_IRQ_BASIC_TIMER            0x00000001
#define BCM2709_INTERRUPT_IRQ_BASIC_MAILBOX          0x00000002
#define BCM2709_INTERRUPT_IRQ_BASIC_DOORBELL0        0x00000004
#define BCM2709_INTERRUPT_IRQ_BASIC_DOORBELL1        0x00000008
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU0_HALTED      0x00000010
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU1_HALTED      0x00000020
#define BCM2709_INTERRUPT_IRQ_BASIC_ILLEGAL_ACCESS_1 0x00000040
#define BCM2709_INTERRUPT_IRQ_BASIC_ILLEGAL_ACCESS_0 0x00000080

#define BCM2709_INTERRUPT_IRQ_BASIC_MASK             0x000000FF

//
// Define the flags for the GPU interrupts included in the basic pending status
// register.
//

#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_7            0x00000400
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_9            0x00000800
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_10           0x00001000
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_18           0x00002000
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_19           0x00004000
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_53           0x00008000
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_54           0x00010000
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_55           0x00020000
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_56           0x00040000
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_57           0x00080000
#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_62           0x00100000

#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_MASK         0x001FFC00

//
// Define the number of bits to shift in order to get to the GPU bits in the
// basic pending register.
//

#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_SHIFT 10

//
// Define the number of GPU registers whose pending status is expressed in the
// basic pending status register.
//

#define BCM2709_INTERRUPT_IRQ_BASIC_GPU_COUNT 11

//
// Define the flags that signify that one of the normal pending status
// registers has a pending interrupt.
//

#define BCM2709_INTERRUPT_IRQ_BASIC_PENDING_1        0x00000100
#define BCM2709_INTERRUPT_IRQ_BASIC_PENDING_2        0x00000200

#define BCM2709_INTERRUPT_IRQ_BASIC_PENDING_MASK     0x00000300

//
// Define the number of GPU interrupt lines on the BCM2709.
//

#define BCM2709_INTERRUPT_GPU_LINE_COUNT 64

//
// Timer Control register bits.
//
// The BCM2709's version of the SP804 does not support one-shot mode and is
// always periodic based on the load value, making those bits defunct. It also
// introduces extra control bits for controlling its extra free-running counter.
//

#define BCM2709_ARM_TIMER_CONTROL_FREE_RUNNING_DIVIDE_MASK  0x00FF0000
#define BCM2709_ARM_TIMER_CONTROL_FREE_RUNNING_DIVIDE_SHIFT 16
#define BCM2709_ARM_TIMER_CONTROL_FREE_RUNNING_ENABLED      0x00000200
#define BCM2709_ARM_TIMER_CONTROL_HALT_ON_DEBUG             0x00000100
#define BCM2709_ARM_TIMER_CONTROL_ENABLED                   0x00000080
#define BCM2709_ARM_TIMER_CONTROL_INTERRUPT_ENABLE          0x00000020
#define BCM2709_ARM_TIMER_CONTROL_DIVIDE_BY_1               0x00000000
#define BCM2709_ARM_TIMER_CONTROL_DIVIDE_BY_16              0x00000004
#define BCM2709_ARM_TIMER_CONTROL_DIVIDE_BY_256             0x00000008
#define BCM2709_ARM_TIMER_CONTROL_32_BIT                    0x00000002
#define BCM2709_ARM_TIMER_CONTROL_16_BIT                    0x00000000

//
// Define the target default frequency to use for the BCM2709 timer, if
// possible.
//

#define BCM2709_ARM_TIMER_TARGET_FREQUENCY 1000000

//
// Define the frequency of the BCM2709 System Timer.
//

#define BCM2709_SYSTEM_TIMER_FREQUENCY 1000000

//
// Run at at a period of 15.625ms.
//

#define BCM2709_CLOCK_TICK_COUNT 15625

//
// Define the maximum predivider.
//

#define BCM2709_TIMER_PREDIVIDER_MAX 0x1FF

//
// Define the GSI for the clock timer.
//

#define BCM2709_CLOCK_TIMER_INTERRUPT 64

//
// Define the channel used to get and set video information by property.
//

#define BCM2709_MAILBOX_PROPERTIES_CHANNEL 8

//
// Define status codes for the BCM2709 mailbox.
//

#define BCM2709_MAILBOX_STATUS_SUCCESS     0x80000000
#define BCM2709_MAILBOX_STATUS_PARSE_ERROR 0x80000001

//
// Define tag response acknowledgement flags.
//

#define BCM2709_MAILBOX_TAG_LENGTH_RESPONSE 0x80000000

//
// Define the tag values for getting basic board information.
//

#define BCM2709_MAILBOX_TAG_GET_BOARD_MODEL    0x00010001
#define BCM2709_MAILBOX_TAG_GET_BOARD_REVISION 0x00010002
#define BCM2709_MAILBOX_TAG_GET_BOARD_SERIAL   0x00010004

//
// Define the tag values for getting the memory region.
//

#define BCM2709_MAILBOX_TAG_GET_ARM_CORE_MEMORY   0x00010005
#define BCM2709_MAILBOX_TAG_GET_VIDEO_CORE_MEMORY 0x00010006

//
// Define the tag value for setting device power states.
//

#define BCM2709_MAILBOX_TAG_SET_POWER_STATE 0x00028001

//
// Define the tag value for getting the clock rate.
//

#define BCM2709_MAILBOX_TAG_GET_CLOCK_RATE     0x00030002
#define BCM2709_MAILBOX_TAG_SET_CLOCK_RATE     0x00038002
#define BCM2709_MAILBOX_TAG_GET_CLOCK_MAX_RATE 0x00030004

//
// Define the tag values for various video information.
//

#define BCM2709_MAILBOX_TAG_GET_FRAME_BUFFER        0x00040001
#define BCM2709_MAILBOX_TAG_GET_PHYSICAL_RESOLUTION 0x00040003
#define BCM2709_MAILBOX_TAG_SET_PHYSICAL_RESOLUTION 0x00048003
#define BCM2709_MAILBOX_TAG_GET_VIRTUAL_RESOLUTION  0x00040004
#define BCM2709_MAILBOX_TAG_SET_VIRTUAL_RESOLUTION  0x00048004
#define BCM2709_MAILBOX_TAG_GET_BITS_PER_PIXEL      0x00040005
#define BCM2709_MAILBOX_TAG_SET_BITS_PER_PIXEL      0x00048005
#define BCM2709_MAILBOX_TAG_GET_PIXEL_ORDER         0x00040006
#define BCM2709_MAILBOX_TAG_SET_PIXEL_ORDER         0x00048006
#define BCM2709_MAILBOX_TAG_GET_ALPHA_MODE          0x00040007
#define BCM2709_MAILBOX_TAG_SET_ALPHA_MODE          0x00048007
#define BCM2709_MAILBOX_TAG_GET_PITCH               0x00040008
#define BCM2709_MAILBOX_TAG_GET_VIRTUAL_OFFSET      0x00040009
#define BCM2709_MAILBOX_TAG_SET_VIRTUAL_OFFSET      0x00048009
#define BCM2709_MAILBOX_TAG_GET_OVERSCAN            0x0004000A
#define BCM2709_MAILBOX_TAG_SET_OVERSCAN            0x0004800A

//
// Define the values for BCM2709 video pixel order.
//

#define BCM2709_MAILBOX_PIXEL_ORDER_BGR 0
#define BCM2709_MAILBOX_PIXEL_ORDER_RGB 1

//
// Define the values for the BCM2709 video alpha mode.
//

#define BCM2709_MAILBOX_ALPHA_MODE_OPAQUE 0
#define BCM2709_MAILBOX_ALPHA_MODE_TRANSPARENT 1
#define BCM2709_MAILBOX_ALPHA_MODE_IGNORED 2

//
// Define the values for the BCM2709 devices.
//

#define BCM2709_MAILBOX_DEVICE_SDHCI 0
#define BCM2709_MAILBOX_DEVICE_USB 3

//
// Define the values for the BCM2709 power states.
//

#define BCM2709_MAILBOX_POWER_STATE_ON 3

//
// Define the ID values for the BCM2709 clocks.
//

#define BCM2709_MAILBOX_CLOCK_ID_EMMC   1
#define BCM2709_MAILBOX_CLOCK_ID_UART   2
#define BCM2709_MAILBOX_CLOCK_ID_ARM    3
#define BCM2709_MAILBOX_CLOCK_ID_VIDEO  4
#define BCM2709_MAILBOX_CLOCK_ID_V3D    5
#define BCM2709_MAILBOX_CLOCK_ID_H264   6
#define BCM2709_MAILBOX_CLOCK_ID_ISP    7
#define BCM2709_MAILBOX_CLOCK_ID_SDRAM  8
#define BCM2709_MAILBOX_CLOCK_ID_PIXEL  9
#define BCM2709_MAILBOX_CLOCK_ID_PWM   10

//
// Define values for the mailbox read and write registers.
//

#define BCM2709_MAILBOX_READ_WRITE_CHANNEL_MASK 0x0000000F
#define BCM2709_MAILBOX_READ_WRITE_DATA_SHIFT 4

//
// Define the alignment for all data sent to the mailbox.
//

#define BCM2709_MAILBOX_DATA_ALIGNMENT 0x00000010

//
// Define values for the mailbox status register.
//

#define BCM2709_MAILBOX_STATUS_READ_EMPTY 0x40000000
#define BCM2709_MAILBOX_STATUS_WRITE_FULL 0x80000000

//
// Define the masks for the various pixel order options. The Raspberry Pi seems
// to only support BGR mode.
//

#define BCM2709_BGR_RED_MASK      0x000000FF
#define BCM2709_BGR_GREEN_MASK    0x0000FF00
#define BCM2709_BGR_BLUE_MASK     0x00FF0000
#define BCM2709_BGR_RESERVED_MASK 0xFF000000
#define BCM2709_RGB_RED_MASK      0x00FF0000
#define BCM2709_RGB_GREEN_MASK    0x0000FF00
#define BCM2709_RGB_BLUE_MASK     0x000000FF
#define BCM2709_RGB_RESERVED_MASK 0xFF000000

//
// Define the default bits per pixel.
//

#define BCM2709_DEFAULT_BITS_PER_PIXEL 32

//
// Define the power management password.
//

#define BCM2709_PRM_PASSWORD 0x5A000000

//
// Define the bits for the power management reset control register.
//

#define BCM2709_PRM_RESET_CONTROL_TYPE_MASK 0x00000030
#define BCM2709_PRM_RESET_CONTROL_TYPE_FULL 0x00000020
#define BCM2709_PRM_RESET_CONTROL_RESET     0x00000102

//
// Define the number of ticks to configure the watchdog timer for on reset.
//

#define BCM2709_PRM_WATCHDOG_RESET_TICKS 10

//
// BCM2835 specific definitions
//

#define BCM2835_BASE 0x20000000

//
// BCM2836 specific definitions
//

//
// Define the base address for global system configuration space.
//

#define BCM2836_BASE 0x3F000000

//
// Define the base address for processor local configuration space.
//

#define BCM2836_LOCAL_BASE 0x40000000

//
// Define the timer interrupt control registers for each CPU.
//

#define BCM2836_CPU_0_TIMER_INTERRUPT_CONTROL (BCM2836_LOCAL_BASE + 0x40)
#define BCM2836_CPU_1_TIMER_INTERRUPT_CONTROL (BCM2836_LOCAL_BASE + 0x44)
#define BCM2836_CPU_2_TIMER_INTERRUPT_CONTROL (BCM2836_LOCAL_BASE + 0x48)
#define BCM2836_CPU_3_TIMER_INTERRUPT_CONTROL (BCM2836_LOCAL_BASE + 0x4C)

//
// Define the mailbox interrupt control registers for each CPU.
//

#define BCM2836_CPU_0_MAILBOX_INTERRUPT_CONTROL (BCM2836_LOCAL_BASE + 0x50)
#define BCM2836_CPU_1_MAILBOX_INTERRUPT_CONTROL (BCM2836_LOCAL_BASE + 0x54)
#define BCM2836_CPU_2_MAILBOX_INTERRUPT_CONTROL (BCM2836_LOCAL_BASE + 0x58)
#define BCM2836_CPU_3_MAILBOX_INTERRUPT_CONTROL (BCM2836_LOCAL_BASE + 0x5C)

//
// Define the IRQ pending registers for the four CPUs.
//

#define BCM2836_CPU_0_IRQ_PENDING (BCM2836_LOCAL_BASE + 0x60)
#define BCM2836_CPU_1_IRQ_PENDING (BCM2836_LOCAL_BASE + 0x64)
#define BCM2836_CPU_2_IRQ_PENDING (BCM2836_LOCAL_BASE + 0x68)
#define BCM2836_CPU_3_IRQ_PENDING (BCM2836_LOCAL_BASE + 0x6C)

//
// Define the FIQ pending registers for the four CPUs.
//

#define BCM2836_CPU_0_FIQ_PENDING (BCM2836_LOCAL_BASE + 0x70)
#define BCM2836_CPU_1_FIQ_PENDING (BCM2836_LOCAL_BASE + 0x74)
#define BCM2836_CPU_2_FIQ_PENDING (BCM2836_LOCAL_BASE + 0x78)
#define BCM2836_CPU_3_FIQ_PENDING (BCM2836_LOCAL_BASE + 0x7C)

//
// Define the mailbox set registers for the four CPUs.
//

#define BCM2836_CPU_0_MAILBOX_0_SET (BCM2836_LOCAL_BASE + 0x80)
#define BCM2836_CPU_0_MAILBOX_1_SET (BCM2836_LOCAL_BASE + 0x84)
#define BCM2836_CPU_0_MAILBOX_2_SET (BCM2836_LOCAL_BASE + 0x88)
#define BCM2836_CPU_0_MAILBOX_3_SET (BCM2836_LOCAL_BASE + 0x8C)
#define BCM2836_CPU_1_MAILBOX_0_SET (BCM2836_LOCAL_BASE + 0x90)
#define BCM2836_CPU_1_MAILBOX_1_SET (BCM2836_LOCAL_BASE + 0x94)
#define BCM2836_CPU_1_MAILBOX_2_SET (BCM2836_LOCAL_BASE + 0x98)
#define BCM2836_CPU_1_MAILBOX_3_SET (BCM2836_LOCAL_BASE + 0x9C)
#define BCM2836_CPU_2_MAILBOX_0_SET (BCM2836_LOCAL_BASE + 0xA0)
#define BCM2836_CPU_2_MAILBOX_1_SET (BCM2836_LOCAL_BASE + 0xA4)
#define BCM2836_CPU_2_MAILBOX_2_SET (BCM2836_LOCAL_BASE + 0xA8)
#define BCM2836_CPU_2_MAILBOX_3_SET (BCM2836_LOCAL_BASE + 0xAC)
#define BCM2836_CPU_3_MAILBOX_0_SET (BCM2836_LOCAL_BASE + 0xB0)
#define BCM2836_CPU_3_MAILBOX_1_SET (BCM2836_LOCAL_BASE + 0xB4)
#define BCM2836_CPU_3_MAILBOX_2_SET (BCM2836_LOCAL_BASE + 0xB8)
#define BCM2836_CPU_3_MAILBOX_3_SET (BCM2836_LOCAL_BASE + 0xBC)

//
// Define the mailbox clear registers for the four CPUs.
//

#define BCM2836_CPU_0_MAILBOX_0_CLEAR (BCM2836_LOCAL_BASE + 0xC0)
#define BCM2836_CPU_0_MAILBOX_1_CLEAR (BCM2836_LOCAL_BASE + 0xC4)
#define BCM2836_CPU_0_MAILBOX_2_CLEAR (BCM2836_LOCAL_BASE + 0xC8)
#define BCM2836_CPU_0_MAILBOX_3_CLEAR (BCM2836_LOCAL_BASE + 0xCC)
#define BCM2836_CPU_1_MAILBOX_0_CLEAR (BCM2836_LOCAL_BASE + 0xD0)
#define BCM2836_CPU_1_MAILBOX_1_CLEAR (BCM2836_LOCAL_BASE + 0xD4)
#define BCM2836_CPU_1_MAILBOX_2_CLEAR (BCM2836_LOCAL_BASE + 0xD8)
#define BCM2836_CPU_1_MAILBOX_3_CLEAR (BCM2836_LOCAL_BASE + 0xDC)
#define BCM2836_CPU_2_MAILBOX_0_CLEAR (BCM2836_LOCAL_BASE + 0xE0)
#define BCM2836_CPU_2_MAILBOX_1_CLEAR (BCM2836_LOCAL_BASE + 0xE4)
#define BCM2836_CPU_2_MAILBOX_2_CLEAR (BCM2836_LOCAL_BASE + 0xE8)
#define BCM2836_CPU_2_MAILBOX_3_CLEAR (BCM2836_LOCAL_BASE + 0xEC)
#define BCM2836_CPU_3_MAILBOX_0_CLEAR (BCM2836_LOCAL_BASE + 0xF0)
#define BCM2836_CPU_3_MAILBOX_1_CLEAR (BCM2836_LOCAL_BASE + 0xF4)
#define BCM2836_CPU_3_MAILBOX_2_CLEAR (BCM2836_LOCAL_BASE + 0xF8)
#define BCM2836_CPU_3_MAILBOX_3_CLEAR (BCM2836_LOCAL_BASE + 0xFC)

//
// ------------------------------------------------------ Data Type Definitions
//

//
// Define the offsets to interrupt controller registers, in bytes.
//

typedef enum _BCM2709_INTERRUPT_REGISTER {
    Bcm2709InterruptIrqPendingBasic = 0x00,
    Bcm2709InterruptIrqPending1     = 0x04,
    Bcm2709InterruptIrqPending2     = 0x08,
    Bcm2709InterruptFiqControl      = 0x0C,
    Bcm2709InterruptIrqEnable1      = 0x10,
    Bcm2709InterruptIrqEnable2      = 0x14,
    Bcm2709InterruptIrqEnableBasic  = 0x18,
    Bcm2709InterruptIrqDisable1     = 0x1C,
    Bcm2709InterruptIrqDisable2     = 0x20,
    Bcm2709InterruptIrqDisableBasic = 0x24,
    Bcm2709InterruptSize            = 0x28,
} BCM2709_INTERRUPT_REGISTER, *PBCM2709_INTERRUPT_REGISTER;

//
// Define the interrupt lines for the non GPU interrupts.
//

typedef enum _BCM2709_CPU_INTERRUPT_LINE {
    Bcm2709InterruptArmTimer       = 64,
    Bcm2709InterruptArmMailbox     = 65,
    Bcm2709InterruptArmDoorbell0   = 66,
    Bcm2709InterruptArmDoorbell1   = 67,
    Bcm2709InterruptGpu0Halted     = 68,
    Bcm2709InterruptGpu1Halted     = 69,
    Bcm2709InterruptIllegalAccess1 = 70,
    Bcm2709InterruptIllegalAccess0 = 71,
    Bcm2709InterruptLineCount      = 72
} BCM2709_CPU_INTERRUPT_LINE, *PBCM2709_CPU_INTERRUPT_LINE;

//
// Define the registers for the timer, in bytes.
//

typedef enum _BCM2709_ARM_TIMER_REGISTER {
    Bcm2709ArmTimerLoadValue           = 0x00,
    Bcm2709ArmTimerCurrentValue        = 0x04,
    Bcm2709ArmTimerControl             = 0x08,
    Bcm2709ArmTimerInterruptClear      = 0x0C,
    Bcm2709ArmTimerInterruptRawStatus  = 0x10,
    Bcm2709ArmTimerInterruptStatus     = 0x14,
    Bcm2709ArmTimerBackgroundLoadValue = 0x18,
    Bcm2709ArmTimerPredivider          = 0x1C,
    Bcm2709ArmTimerFreeRunningCounter  = 0x20,
    Bcm2709ArmTimerRegisterSize        = 0x24
} BCM2709_TIMER_REGISTER, *PBCM2709_TIMER_REGISTER;

//
// Define the registers for the System timer, in bytes.
//

typedef enum _BCM2709_SYSTEM_TIMER_REGISTER {
    Bcm2709SystemTimerControl      = 0x00,
    Bcm2709SystemTimerCounterLow   = 0x04,
    Bcm2709SystemTimerCounterHigh  = 0x08,
    Bcm2709SystemTimerCompare0     = 0x0C,
    Bcm2709SystemTimerCompare1     = 0x10,
    Bcm2709SystemTimerCompare2     = 0x14,
    Bcm2709SystemTimerCompare3     = 0x18,
    Bcm2709SystemTimerRegisterSize = 0x1C
} BCM2709_SYSTEM_TIMER_REGISTER, *PBCM2709_SYSTEM_TIMER_REGISTER;

//
// Register set definition for the BCM2709 mailbox. These are offsets in bytes,
//

typedef enum _BCM2709_MAILBOX_REGISTER {
    Bcm2709MailboxRead   = 0x0,
    Bcm2709MailboxPeak   = 0x10,
    Bcm2709MailboxSender = 0x14,
    Bcm2709MailboxStatus = 0x18,
    Bcm2709MailboxConfig = 0x1C,
    Bcm2709MailboxWrite  = 0x20
} BCM2709_MAILBOX_REGISTER, *PBCM2709_MAILBOX_REGISTER;

//
// Define the offsets to power management registers, in bytes.
//

typedef enum _BCM2709_PRM_REGISTER {
    Bcm2709PrmResetControl = 0x1C,
    Bcm2709PrmResetStatus  = 0x20,
    Bcm2709PrmWatchdog     = 0x24,
} BCM2709_PRM_REGISTER, *PBCM2709_PRM_REGISTER;

//
// -------------------------------------------------------------------- Globals
//

//
// -------------------------------------------------------- Function Prototypes
//