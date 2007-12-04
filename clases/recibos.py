from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer
from reportlab.platypus.flowables import PageBreak
from reportlab.lib.styles import getSampleStyleSheet
from reportlab.lib.pagesizes import A4
from reportlab.rl_config import defaultPageSize
from reportlab.lib.units import inch


nombres=['Sandra Royo Pérez']


Nota="""
Este recibo de pago es además el resguardo de la inscripción
al curso, debe conservarse hasta el inicio del mismo, momento
en el que se efectuará el control de asistencia.
"""

styles = getSampleStyleSheet()

if __name__=='__main__':
    doc = SimpleDocTemplate("recibos.pdf",pagesize=A4)
    Story = []
    for nombre in nombres:
        Story.append(Paragraph('Recibo',styles["Heading1"]))
        Story.append(Paragraph("""
        <para fontSize=12>Fecha:.............................</para>
        """,
                               styles["BodyText"]))
        Story.append(Paragraph("""
        <para fontSize=12>Recibo correspondiente al curso <i>Introducción
        Informal a Matlab y Octave</i> de %s.  Diez Euros (10€)</para>
        """%(nombre),styles["BodyText"]))
        Story.append(Paragraph(Nota,styles["BodyText"]))
        Story.append(Spacer(1,0.5*inch))
        Story.append(Paragraph("""
        <para alignment=right>Delegación de Alumnos ETSI
        Aeronáuticos</para>
        """,styles["BodyText"]))
        Story.append(Spacer(1,inch))
        Story.append(Paragraph("""<para alignment=center>
        ...........................................................
        </para>
        """,styles["BodyText"]))
        Story.append(Paragraph("""
        Sellar el recibo, cortar por la línea de puntos y guardar el
        resguardo
        """,styles["BodyText"]))
        Story.append(Spacer(1,0.5*inch))
        Story.append(Paragraph('Resguardo',styles["Heading1"]))
        Story.append(Paragraph("""
        <para fontSize=12>Resguardo de pago de %s.</para>
        """%(nombre),styles["BodyText"]))
        
        Story.append(PageBreak())
        
    doc.build(Story)
