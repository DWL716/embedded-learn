## TIM定时器结构体详解

### TIM_TimeBaseInitTypeDef

``` c
typedef struct
 {
  uint16_t TIM_Prescaler; // 预分频器
  uint16_t TIM_CounterMode; // 计数模式
  uint32_t TIM_Period; // 定时器周期
  uint16_t TIM_ClockDivision; // 时钟分频
  uint8_t TIM_RepetitionCounter; // 重复计算器
 } TIM_TimeBaseInitTypeDef;

```
(1) TIM_Prescaler：定时器预分频器设置，时钟源经该预分频器才是定时器计数时钟CK_CNT，它设定 PSC 寄存器的值。计算公式为：计数器时钟频率 (f CK_CNT ) 等于f CK_PSC / (PSC[15:0] + 1)，可实现 1至 65536 分频。(注：CK_CNT 和CK_PSC为下标)
(2) TIM_CounterMode：定时器计数方式，可设置为向上计数、向下计数以及中心对齐。高级控制定时器允许选择任意一种。
(3) TIM_Period：定时器周期，实际就是设定自动重载寄存器 ARR的值，ARR 为要装载到实际自动重载寄存器（即影子寄存器）的值，可设置范围为 0至 65535。
(4) TIM_ClockDivision：时钟分频，设置定时器时钟 CK_INT 频率与死区发生器以及数字滤波器采样时钟频率分频比。可以选择 1、2、4分频。
(5) TIM_RepetitionCounter：重复计数器，只有 8 位，只存在于高级定时器。
————————————————

### TIM_OCInitTypeDef

``` c
  typedef struct {
    uint16_t TIM_OCMode; // 比较输出模式
    uint16_t TIM_OutputState; // 比较输出使能
    uint16_t TIM_OutputNState; // 比较互补输出使能
    uint32_t TIM_Pulse; // 脉冲宽度
    uint16_t TIM_OCPolarity; // 输出极性
    uint16_t TIM_OCNPolarity; // 互补输出极性
    uint16_t TIM_OCIdleState; // 空闲状态下比较输出状态
    uint16_t TIM_OCNIdleState; // 空闲状态下比较互补输出状态
  } TIM_OCInitTypeDef;

```

(1) TIM_OCMode：比较输出模式选择，总共有八种，常用的为 PWM1/PWM2。它设定CCMRx寄存器 OCxM[2:0]位的值。
(2) TIM_OutputState：比较输出使能，决定最终的输出比较信号 OCx是否通过外部引脚输出。它设定 TIMx_CCER寄存器 CCxE/CCxNE 位的值。
(3) TIM_OutputNState:比较互补输出使能，决定 OCx的互补信号 OCxN是否通过外部引脚输出。它设定 CCER 寄存器 CCxNE 位的值。
(4) TIM_Pulse：比较输出脉冲宽度，实际设定比较寄存器 CCR 的值，决定脉冲宽度。可设置范围为 0至 65535。
(5) TIM_OCPolarity：比较输出极性，可选 OCx为高电平有效或低电平有效。它决定着定时器通道有效电平。它设定 CCER寄存器的 CCxP位的值。
(6) TIM_OCNPolarity：比较互补输出极性，可选 OCxN 为高电平有效或低电平有效。它设定 TIMx_CCER寄存器的 CCxNP 位的值。
(7) TIM_OCIdleState：空闲状态时通道输出电平设置，可选输出 1 或输出 0，即在空闲状态(BDTR_MOE位为 0)时，经过死区时间后定时器通道输出高电平或低电平。它设定CR2 寄存器的 OISx 位的值。
(8) TIM_OCNIdleState：空闲状态时互补通道输出电平设置，可选输出 1或输出 0，即在空闲状态(BDTR_MOE 位为 0)时，经过死区时间后定时器互补通道输出高电平或低电平，设定值必须与 TIM_OCIdleState 相反。它设定是 CR2 寄存器的 OISxN 位的值。
————————————————

### TIM_ICInitTypeDef

``` c
  typedef struct {
    uint16_t TIM_Channel; // 输入通道选择
    uint16_t TIM_ICPolarity; // 输入捕获触发选择
    uint16_t TIM_ICSelection; // 输入捕获选择
    uint16_t TIM_ICPrescaler; // 输入捕获预分频器
    uint16_t TIM_ICFilter; // 输入捕获滤波器
 } TIM_ICInitTypeDef;

```

(1) TIM_Channel：捕获通道 ICx选择，可选 TIM_Channel_1、TIM_Channel_2、TIM_Channel_3或 TIM_Channel_4四个通道。它设定 CCMRx 寄存器 CCxS 位 的值。
(2) TIM_ICPolarity：输入捕获边沿触发选择，可选上升沿触发、下降沿触发或边沿跳变触发。它设定 CCER寄存器 CCxP 位和 CCxNP 位的值。
(3) TIM_ICSelection：输入通道选择，捕获通道 ICx的信号可来自三个输入通道，分别为
TIM_ICSelection_DirectTI、TIM_ICSelection_IndirectTI或 TIM_ICSelection_TRC，具体的区别见下图 1所示。如果是普通的输入捕获，4个通道都可以使用，如果是 PWM输入则只能使用通道 1 和通道 2。它设定 CCRMx 寄存器的 CCxS[1:0]位的值。
(4) TIM_ICPrescaler：输入捕获通道预分频器，可设置 1、2、4、8 分频，它设定 CCMRx寄存器的 ICxPSC[1:0]位的值。如果需要捕获输入信号的每个有效边沿，则设置 1分频即可。
(5) TIM_ICFilter：输入捕获滤波器设置，可选设置 0x0至 0x0F。它设定 CCMRx寄存器ICxF[3:0]位的值。一般我们不使用滤波器，即设置为 0。
————————————————

### TTIM_BDTRInitTypeDef

``` c
  typedef struct {
    uint16_t TIM_OSSRState; // 运行模式下的关闭状态选择
    uint16_t TIM_OSSIState; // 空闲模式下的关闭状态选择
    uint16_t TIM_LOCKLevel; // 锁定配置
    uint16_t TIM_DeadTime; // 死区时间
    uint16_t TIM_Break; // 断路输入使能控制
    uint16_t TIM_BreakPolarity; // 断路输入极性
    uint16_t TIM_AutomaticOutput; // 自动输出使能
  } TIM_BDTRInitTypeDef;

```

(1) TIM_OSSRState：运行模式下的关闭状态选择，它设定 BDTR寄存器 OSSR位的值。
(2) TIM_OSSIState：空闲模式下的关闭状态选择，它设定 BDTR 寄存器 OSSI位的值。
(3) TIM_LOCKLevel：锁定级别配置， BDTR寄存器 LOCK[1:0]位的值。
(4) TIM_DeadTime：配置死区发生器，定义死区持续时间，可选设置范围为 0x0至0xFF。它设定 BDTR 寄存器 DTG[7:0]位的值。
(5) TIM_Break：断路输入功能选择，可选使能或禁止。它设定 BDTR寄存器 BKE 位的值。
(6) TIM_BreakPolarity：断路输入通道 BRK极性选择，可选高电平有效或低电平有效。它设定 BDTR寄存器 BKP 位的值。
(7) TIM_AutomaticOutput：自动输出使能，可选使能或禁止，它设定BDTR寄存器 AOE位的值。
————————————————
