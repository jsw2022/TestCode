#include <stdio.h>

//Declare a function pointer for the application
typedef void(*pfJumpToApplication)(void);

typedef uint32 uint32_t;

//Assumed,starting address of the application
#define APPLICATION_STARTING_ADDRESS   (uint32_t)0x08020000

static void JumpToApplication(void)
{
    //Create function pointer for the user application
    pfJumpToApplication JumpToAppFun = NULL;
    uint32_t *pApplicationAddress=(uint32_t *)APPLICATION_STARTING_ADDRESS;
    
    //Disabling the interrupts, before changing interrupt vectors
    __disable_irq();
    
    //Set vector table
    SCB->VTOR = (uint32_t *)pApplicationAddress;
    
    //Initialize the user application's Stack Pointer
    __set_MSP(APPLICATION_STARTING_ADDRESS);
    
    //Address for the user Application
    JumpToAppFun = (pfJumpToApplication)(APPLICATION_STARTING_ADDRESS +4);
    
    //Jump to the application
    JumpToAppFun();
}

int main()
{
    JumpToApplication();
    
    return 0;
}
