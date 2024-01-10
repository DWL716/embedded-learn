| 函数 | 说明 |
| :--: | :--: |
| OLED_Init(); | 初始化 |
| OLED_Clear(); | 清屏 |
| OLED_ShowChar(1, 1, 'A'); | 显示一个字符 |
| OLED_ShowString(1, 3, "HelloWorld!"); | 显示字符串 |
| OLED_ShowNum(2, 1, 12345, 5); | 显示十进制数字 |
| OLED_ShowSignedNum(2, 7, -66, 2); | 显示有符号十进制数字 |
| OLED_ShowHexNum(3, 1, 0xAA55, 4); | 显示十六进制数字 |
| OLED_ShowBinNum(4, 1, 0xAA55, 16); | 显示二进制数字 |

<!-- 显示数字需要将数字长度传进去 -->
#### 部分函数 params 说明
``` c
/** 显示无符合的数字
 * param x 显示位置x
 * param y 显示位置y
 * param num 要显示的数字
 * param len 数字长度
 */
OLED_ShowNum(2, 1, 12345, 5);

/** 显示有符合的数字
 * param x 显示位置x
 * param y 显示位置y
 * param num 要显示的有符合的数字
 * param len 数字长度
 */
OLED_ShowSignedNum(2, 7, -66, 2);

/** 显示字符
 * param x 显示位置x
 * param y 显示位置y
 * param ch 要显示的字符
*/
OLED_ShowChar(1, 1, 'A');

```
