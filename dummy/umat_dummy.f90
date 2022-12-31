module mymod
interface
function addfortran(x,y) bind(C, name='addf')
    use, intrinsic :: iso_c_binding
    real(c_float), intent(in), value  :: x, y
    !real(c_float) :: sum
end function addfortran
!
! subroutine determinantf(m,d) bind(C, name='detc')
!     use, intrinsic :: iso_c_binding
!     real(c_double), dimension(3,3), intent(in)  :: m
!     real(c_float), intent(out) :: d
! end subroutine determinantf
end interface
end module mymod

SUBROUTINE umat(f,s,d)
!
use mymod
IMPLICIT NONE

real, dimension(3,3) :: f
!real, intent(in out) :: s,d
real :: s,d, summ

summ = addfortran(s,d)
!call determinantf(f,ff)

write(*,*) s,d,summ,s+d
!print *, ff
return
end subroutine umat