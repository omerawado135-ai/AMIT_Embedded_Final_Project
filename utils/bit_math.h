/*
 * bit_math.h
 *
 *  Created on: ١٦‏/٠٨‏/٢٠٢٦
 *      Author: Omar
 */

#ifndef UTILS_BIT_MATH_H_
#define UTILS_BIT_MATH_H_

#define CLR_BIT(reg,bit)        reg &= (~(1 << bit))
#define SET_BIT(reg,bit)        reg |= ( 1 << bit )
#define TOG_BIT(reg,bit)        reg ^= ( 1 << bit )
#define GET_BIT(reg,bit)        ((reg >> bit) & 1)
#define MERGE(num1, num2)       ((num1) * 10 + (num2))


#endif /* UTILS_BIT_MATH_H_ */
