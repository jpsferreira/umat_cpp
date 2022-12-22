PROGRAM TEST_GENERAL_UMAT
INCLUDE 'aba_param.inc'

DOUBLE PRECISION STRESS,DDSDDE
!
STRESS = 1.0
DDSDDE = 2.0
CALL UMAT(STRESS,DDSDDE)

 write(*,*) STRESS
 write(*,*)
 write(*,*) DDSDDE
!################################################################################################!
!
END PROGRAM
