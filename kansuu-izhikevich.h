/* Copyright (c) 2021 RT-JP All Right Reserved. */
 
//Gaussian distribution
double DistGauss(double x_1, double y_1, double x_2, double y_2, double w_dist, double sigma_dist);
//Membrane potential and recovery variable
double runge_V(double *vr, double *ur, double *Ir);
double runge_U(double *vr, double *ur, double ar, double br);

double func_V(double vf, double uf, double  If);
double func_U(double vf, double  uf, double af, double bf);
//Neuron output
double runge_X(double *xr, double x_lambdar, double *Deltar, double tau_xr);
double func_X(double xf, double x_lambdaf, double  Deltaf, double tau_xf);

//Gaussian distribution
double DistGauss(double x_1, double y_1, double x_2, double y_2, double w_dist, double sigma_dist){
	double DistGauss_W = 0.0;
	double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0;
	double a = 0.0, b = 0.0, c = 0.0, d = 0.0;
	x1 = x_1;
	y1 = y_1;
	x2 = x_2;
	y2 = y_2;
	a = (x1 - x2) * (x1 - x2);
	b = (y1 - y2) * (y1 - y2);
	c = a + b;
	d = 2 * sigma_dist * sigma_dist;
	DistGauss_W = w_dist * exp((-1 * c) / d);
	return DistGauss_W;
}

//Membrane potential and recovery variable
double runge_V(double *vr, double *ur, double *Ir) {
	double v_DT;
	v_DT = 0.1;
	double v_k, v_k1, v_k2, v_k3, v_k4;
	double u_k, u_k1, u_k2, u_k3, u_k4;
	v_k = v_k1 = v_k2 = v_k3 = v_k4 = 0.0;
	u_k = u_k1 = u_k2 = u_k3 = u_k4 = 0.0;
	v_k1 = v_DT * func_V(*vr, *ur, *Ir);
	v_k2 = v_DT * func_V(*vr + v_k1*0.5, *ur + u_k1*0.5, *Ir);
	v_k3 = v_DT * func_V(*vr + v_k2*0.5, *ur + u_k2*0.5, *Ir);
	v_k4 = v_DT * func_V(*vr + v_k3, *ur + u_k3, *Ir);
	v_k = (v_k1 + (2 * v_k2) + (2 * v_k3) + v_k4) / 6.0;
	*vr = *vr + v_k;
	return *vr;
}

double runge_U(double *vr, double *ur, double ar, double br) {
	double v_DT;
	v_DT = 0.1;
	double v_k, v_k1, v_k2, v_k3, v_k4;
	double u_k, u_k1, u_k2, u_k3, u_k4;
	u_k = u_k1 = u_k2 = u_k3 = u_k4 = 0.0;
	u_k1 = v_DT * func_U(*vr, *ur, ar, br);
	u_k2 = v_DT * func_U(*vr + v_k1*0.5, *ur + u_k1*0.5, ar, br);
	u_k3 = v_DT * func_U(*vr + v_k2*0.5, *ur + u_k2*0.5, ar, br);
	u_k4 = v_DT * func_U(*vr + v_k3, *ur + u_k3, ar, br);
	u_k = (u_k1 + (2 * u_k2) + (2 * u_k3) + u_k4) / 6.0;
	*ur = *ur + u_k;

	return *ur;
}

double func_V(double vf, double uf, double If) {
	double V = 0.0;
	V = ((0.04*vf*vf)+(5*vf)+140-uf+If);
	return V;
}

double func_U(double vf, double uf, double af, double bf) {
	double U = af*(bf*vf - uf);
	return U;
}

//Neuron output
double runge_X(double *xr, double x_lambdar, double *Deltar, double tau_xr){
	double x_k, x_k1, x_k2, x_k3, x_k4;
	double x_DT;
	x_k = x_k1 = x_k2 = x_k3 = x_k4 = 0.0;
	x_DT = 0.1;
	x_k1 = x_DT * func_X(*xr, x_lambdar, *Deltar, tau_xr);
	x_k2 = x_DT * func_X(*xr + x_k1 / 2.0, x_lambdar, *Deltar, tau_xr);
	x_k3 = x_DT * func_X(*xr + x_k2 / 2.0, x_lambdar, *Deltar, tau_xr);
	x_k4 = x_DT * func_X(*xr + x_k3, x_lambdar, *Deltar, tau_xr);
	x_k = (x_k1 + (2 * x_k2) + (2 * x_k3) + x_k4) / 6.0;
	*xr = *xr + x_k;
	return *xr;
}

double func_X(double xf, double x_lambdaf, double Deltaf, double tau_xf){
	return ((-1 * xf) + (x_lambdaf * Deltaf)) / (tau_xf);
}
