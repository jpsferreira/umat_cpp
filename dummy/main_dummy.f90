PROGRAM TEST_GENERAL_UMAT
INCLUDE 'aba_param.inc'

real :: DFGRD1(3,3)
real :: STRESS,DDSDDE
!
 DFGRD1(1,1)=  1.0
 DFGRD1(1,2)=  0.25
 DFGRD1(1,3)=  0.0
 DFGRD1(2,1)=  0.0
 DFGRD1(2,2)=  1/sqrt(DFGRD1(1,1))
 DFGRD1(2,3)=  0.0
 DFGRD1(3,1)=  0.0
 DFGRD1(3,2)=  0.0
 DFGRD1(3,3)=  1/sqrt(DFGRD1(1,1))
 !
STRESS = 1.0
DDSDDE = 2.0

CALL UMAT(DFGRD1,STRESS,DDSDDE)

 write(*,*) STRESS
 write(*,*)
 write(*,*) DDSDDE
!################################################################################################!
!
END PROGRAM
