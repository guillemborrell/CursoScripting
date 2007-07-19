function[polinom]=polyadd(polin1,polin2)
 if length(polin1)<length(polin2)
 corto=polin1;
 lungo=polin2;
 else
 corto=polin2;
 lungo=polin1;
 end
 diff=length(lungo)-length(corto);
 if diff>0
 polinom=[zeros(1,diff),corto]+lungo;
 else
 polinom=lungo+corto;
 end