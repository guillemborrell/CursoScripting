# -*- coding: utf-8 -*-
from __future__ import division
try:
    from xml.etree.ElementTree import parse
except ImportError:
    from elementtree import parse

import pylab as P
from numpy import array,linspace
from scipy import interp
from scipy.optimize import leastsq

class Top500FileLoader(object):
    """
    This class handles the Top500 list in the XML given format.
    """
    def __init__(self,file='TOP500_200906_all.xml'):
        try:
            list = open(file,'r')
        except IOError:
            raise "File not found"

        print "Loading Top500 file..."

        tree = parse(list)
        self.list = tree.getroot()

    @property
    def numberOfProcessors(self):
        """
        Gives the number of processors ordered with the rank
        """
        
        return [int(site.getchildren()[12].text) \
                    for site in self.list.getchildren()]

    def plotNumberOfProcessors(self,figure=1):
        P.figure(figure)
        P.clf()
        P.plot(self.numberOfProcessors)
        P.title('Number of processors')
        P.ylabel('Processors')
        P.xlabel('Rank')

    @property
    def rMax(self):
        """
        Gives a list of the Rmax
        """  
        return [float(site.getchildren()[5].text) \
                    for site in self.list.getchildren()]

    def plotRMax(self,figure=2):
        P.figure(figure)
        P.clf()
        P.plot(self.rMax)
        P.title('r-max')
        P.ylabel('GigaFlops')
        P.xlabel('Rank')

    def plotRMaxFit(self,figure=2):
        y0 = array(self.rMax).astype('d')/1000
        x0 = linspace(1,500,500).astype('d')
        points = lambda x: interp(x,x0,y0)
        pareto = lambda v, x: v[0]/x**v[1]
        fp = lambda v, x: points(x)-v[0]/x**v[1]
        v0 = [1.0,1.0]
        (v, success) = leastsq(fp, v0, args=(x0,))
        P.figure(figure)
        P.clf()
        P.hold('on')
        P.plot(y0)
        P.plot(x0,pareto(v,x0))
        P.axis([0,500,0,1100])
        P.title('r-max')
        P.ylabel('TeraFlops')
        P.xlabel('Rank')
        P.legend(['Top500','Pareto fit'])
        P.text(100, 750, r'$r_{max}(x) = Cx^{-\alpha},\ C=%s,\ \alpha=%s$'\
                   %(str(v[0])[:6],str(v[1])[:6]),
               fontsize=20,bbox = dict(boxstyle="round",
                                       ec=(1., 0.5, 0.5),
                                       fc=(1., 0.8, 0.8),
                                       ))

    @property
    def rPeak(self):
        """
        Gives a list of the Rpeak
        """
        return [float(site.getchildren()[13].text) \
                    for site in self.list.getchildren()]

    def plotRPeak(self,figure=3):
        P.figure(figure)
        P.clf()
        P.plot(array(self.rPeak)/1000)
        P.title('r-peak')
        P.ylabel('TeraFlops')
        P.xlabel('Rank')


    def show(self):
        P.show()


if __name__ == '__main__':
    statistics = Top500FileLoader()
    statistics.plotRMaxFit()
    statistics.show()
