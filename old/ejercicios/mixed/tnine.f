      SUBROUTINE TNINE (IOPT, PARMOD, PS, X, Y, Z, BX, BY, BZ)
      INTEGER IOPT
      DOUBLE PRECISION PARMOD(10), PS, X, Y, Z, BX, BY, BZ    
C     This is just a test subroutine body, to check connexions.
C     Put the sum of PARMOD in PS, and X, Y, Z into BX, BY, BZ
      INTEGER I
      PS = 0D0
      DO I=1, 10
         PS = PS + PARMOD (I)
      END DO
      BX = X
      BY = Y
      BZ = Z
      END
