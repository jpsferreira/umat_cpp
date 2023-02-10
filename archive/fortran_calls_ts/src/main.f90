! fortran program main
!
! calls c++ function invariant_nn, which calls a torchscript with
! a neural network
!

program main

    ! define interface to interact with c++
    use, intrinsic :: iso_c_binding, only: c_float
    implicit none
    interface invariant_nn
        subroutine invariant_nn(I, G) bind (c)
            import :: c_float
            real(c_float) :: I(1)
            real(c_float) :: G(1)
        end subroutine
    end interface

    ! fortran program
    real(4) I(1), G(1)

    ! invariants
    I(1) = 1.01
    print *, "Tensor invariants ", I

    ! tensor basis coefficients
    call invariant_nn(I, G)    
    print *, "Tensor basis coefficients ", G

end program main