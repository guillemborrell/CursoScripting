function genmat(E,I,L,A,phi)

! Esta rutina genera la matriz de rigidez para una sección de barra
! reticulada en ejes globales.  Sus argumentos son:

! E: Módulo Elástico
! I: Momento de Inercia de la sección de la barra
! L: Longitud de la barra
! A: Área de la barra
! phi: Ángulo de la barra respecto a la horizontal medido contrahorariamente

real*8, dimension(6,6) :: genmat
real*8 :: E,I,L,A,phi

genmat(1,1) = (12d0*E*I/L**3)*sin(phi)**2+(E*A/L)*cos(phi)**2
genmat(1,2) = (E*A/L)*cos(phi)*sin(phi)-(12d0*E*I/L**3)*cos(phi)*sin(phi)
genmat(1,3) = -(6d0*E*I/L**2)*sin(phi)
genmat(1,4) = -(12d0*E*I/L**3)*sin(phi)**2-(E*A/L)*cos(phi)**2
genmat(1,5) = (12d0*E*I/L**3)*cos(phi)*sin(phi)-(E*A/L)*cos(phi)*sin(phi)
genmat(1,6) = -(6d0*E*I/L**2)*sin(phi)
genmat(2,1) = (E*A/L)*cos(phi)*sin(phi)-(12d0*E*I/L**3)*cos(phi)*sin(phi)
genmat(2,2) = (E*A/L)*sin(phi)**2+(12d0*E*I/L**3)*cos(phi)**2
genmat(2,3) = (6d0*E*I/L**2)*cos(phi)
genmat(2,4) = (12d0*E*I/L**3)*cos(phi)*sin(phi)-(E*A/L)*cos(phi)*sin(phi)
genmat(2,5) = -(E*A/L)*sin(phi)**2-(12d0*E*I/L**3)*cos(phi)**2
genmat(2,6) = (6d0*E*I/L**2)*cos(phi)
genmat(3,1) = -(6d0*E*I/L**2)*sin(phi)
genmat(3,2) = (6d0*E*I/L**2)*cos(phi)
genmat(3,3) = (4d0*E*I/L)
genmat(3,4) = (6d0*E*I/L**2)*sin(phi)
genmat(3,5) = -(6d0*E*I/L**2)*cos(phi)
genmat(3,6) = 2d0*E*I/L
genmat(4,1) = -(12d0*E*I/L**3)*sin(phi)**2-(E*A/L)*cos(phi)**2
genmat(4,2) = (12d0*E*I/L**3)*cos(phi)*sin(phi)-(E*A/L)*cos(phi)*sin(phi)
genmat(4,3) = (6d0*E*I/L**2)*sin(phi)
genmat(4,4) = (12d0*E*I/L**3)*sin(phi)**2+(E*A/L)*cos(phi)**2
genmat(4,5) = (E*A/L)*cos(phi)*sin(phi)-(12d0*E*I/L**3)*cos(phi)*sin(phi)
genmat(4,6) = (6d0*E*I/L**2)*sin(phi)
genmat(5,1) = (12d0*E*I/L**3)*cos(phi)*sin(phi)-(E*A/L)*cos(phi)*sin(phi)
genmat(5,2) = -(E*A/L)*sin(phi)**2-(12d0*E*I/L**3)*cos(phi)**2
genmat(5,3) = -(6d0*E*I/L**2)*cos(phi)
genmat(5,4) = (E*A/L)*cos(phi)*sin(phi)-(12d0*E*I/L**3)*cos(phi)*sin(phi)
genmat(5,5) = (E*A/L)*sin(phi)**2+(12d0*E*I/L**3)*cos(phi)**2
genmat(5,6) = -(6d0*E*I/L**2)*cos(phi)
genmat(6,1) = -(6d0*E*I/L**2)*sin(phi)
genmat(6,2) = (6d0*E*I/L**2)*cos(phi)
genmat(6,3) = 2d0*E*I/L
genmat(6,4) = (6d0*E*I/L**2)*sin(phi)
genmat(6,5) = -(6d0*E*I/L**2)*cos(phi)
genmat(6,6) = (4d0*E*I/L)

! Y llegados aquí todos se preguntan... Guillem. ¿Cómo haces para escribir
! estos cipotes y no equivocarte? Pues no escribiendolos

end function genmat
