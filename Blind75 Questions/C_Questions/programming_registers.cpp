/**
 * @file programming_registers.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-10-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include<stdint.h>

#define NPU_CTRL_REG (*(volatile uint32_t*)0X5000)
#define NPU_STATUS (*(volatile uint32_t*)0x5004)

/**
 * @brief Clean C++ Register
 * 
 */
class Register {
    volatile uint32_t* addr;
public:
    Register(uintptr_t address) : addr(reinterpret_cast<volatile uint32_t*>(address)) {}

    void write(uint32_t val) { *addr = val; }
    uint32_t read() const { return *addr; }

    void setBits(uint32_t mask)   { *addr |= mask; }
    void clearBits(uint32_t mask) { *addr &= ~mask; }
};

void useRegClass(void){
    Register GPIO_ODR(0x48000014);
    GPIO_ODR.setBits(1 << 5); // Turn LED ON
    GPIO_ODR.clearBits(1 << 5); // Turn LED OFF

}


int main (void){

    /* BIT MASK METHOD */
    #define PERIPH_ENABLE_BIT   (1U << 0)
    #define PERIPH_MODE_MASK    (0x7 << 1)
    #define PERIPH_RESET_BIT    (1U << 8)

    volatile uint32_t *PERIPH_CTRL = (uint32_t *)0x40020000;

    // Enable peripheral
    *PERIPH_CTRL |= PERIPH_ENABLE_BIT;

    // Set mode to 3
    *PERIPH_CTRL = (*PERIPH_CTRL & ~PERIPH_MODE_MASK) | (3 << 1);

    // Reset peripheral
    *PERIPH_CTRL |= PERIPH_RESET_BIT;


    /* BIT FIELD METHOD */
    typedef struct {
        uint32_t ENABLE : 1;
        uint32_t MODE   : 3;
        uint32_t        : 4;  // Reserved bits
        uint32_t RESET  : 1;
    } PERIPH_CTRL_t;

    #define PERIPH_CTRL ((volatile PERIPH_CTRL_t *)0x40020000)

    // Use like this
    PERIPH_CTRL->ENABLE = 1;
    PERIPH_CTRL->MODE   = 3;
    PERIPH_CTRL->RESET  = 1;

    /* REGISTER MAPS */
    #define LED_PIN 5

    typedef struct {
        volatile uint32_t MODER;    // Mode register
        volatile uint32_t OTYPER;   // Output type register
        volatile uint32_t OSPEEDR;  // Output speed register
        volatile uint32_t PUPDR;    // Pull-up/pull-down register
        volatile uint32_t IDR;      // Input data register
        volatile uint32_t ODR;      // Output data register
        // ... other registers
    } GPIO_TypeDef;

    #define GPIOA ((GPIO_TypeDef *)0x48000000)

    // Usage
    GPIOA->MODER &= ~(0x3 << (LED_PIN * 2));
    GPIOA->MODER |=  (0x1 << (LED_PIN * 2));
    GPIOA->ODR   ^=  (1 << LED_PIN);


    /* Testing */
    typedef struct programming_registers
    {
        /* data */
        volatile uint32_t STATUS;
        volatile uint32_t MODE;
        volatile uint32_t POWER;
        volatile uint32_t ADDR;

    } GPIO_Register;

    #define REC0 ((GPIO_Register *) 0x48000000)

    REC0->ADDR = 5;

    


    return 0;
}