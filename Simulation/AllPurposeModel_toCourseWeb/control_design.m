clc, clear vars io

io(4) = linio('Modified/Vehicle1',1,'openoutput');
io(5) = linio('Modified/Vehicle1',2,'openoutput');
io(6) = linio('Modified/Vehicle1',3,'openoutput');
io(7) = linio('Modified/Vehicle1',4,'openoutput');
io(8) = linio('Modified/Vehicle1',5,'openoutput');
io(9) = linio('Modified/Vehicle1',6,'openoutput');

io(1) = linio('Modified/C4',1,'openinput');
io(2) = linio('Modified/C5',1,'openinput');
io(3) = linio('Modified/C6',1,'openinput');



setlinio('Modified',io);
linsys = linearize('Modified',io);