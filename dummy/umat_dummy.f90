module mymod
use, intrinsic :: iso_c_binding
interface
subroutine addfortran(x,y,sum) bind(C, name='addf')
    use, intrinsic :: iso_c_binding
    real(c_float) :: x, y
    real(c_float) :: sum
end subroutine addfortran
end interface
end module mymod

SUBROUTINE umat(a,b)
!
use mymod
IMPLICIT NONE

real :: a,b,c

call addfortran(a,b,c)

print *, c
return
end subroutine umat