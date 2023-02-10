module mymod
use, intrinsic :: iso_c_binding, only: c_float
interface dl_model
subroutine dl_model(I, G) bind (c)
    import :: c_float
    real(c_float) :: I(1)
    real(c_float) :: G(1)
end subroutine
end interface
end module mymod

SUBROUTINE umat(I,G)
!
use mymod
IMPLICIT NONE

! fortran program
real(4) I(1), G(1)

print *, "Tensor invariants ", I

call dl_model(I, G)   
print *, "Tensor basis coefficients ", G

return
end subroutine umat