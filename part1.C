// Line fitting macro written for ROOT
{

//   Part 1

  const int ndata = 9;

  float x[ndata] = {300,  320,	340,	360,	380,	400,	420,	440,	460};
  float y[ndata] = {0, 0, 0, 448, 537,	533,	502,	502,	540};
  float sx[ndata]= {0, 0, 0, 0, 0, 0, 0, 0, 0};
  float sy[ndata]= {0, 0, 0, 21.2, 23.2, 23.1, 22.4, 22.4, 23.2};


  float weight = 0;
  float totw = 0; // Total weight
  float xybar = 0, xbar = 0, ybar = 0, x2bar = 0; // weighted averages

  for (int i=0; i<ndata; ++i) {
    weight = 1./(sy[i]*sy[i]);
    totw += weight;
    xybar += (x[i]*y[i]*weight);
    xbar += (x[i]*weight);
    ybar += (y[i]*weight);
    x2bar += (x[i]*x[i]*weight);
  }

  xybar /= totw;
  xbar /= totw;
  ybar /= totw;
  x2bar /= totw;

  float sy2bar = ndata / totw; // weighted average error squared
  float slope = (xybar - xbar*ybar) / (x2bar - xbar*xbar);
  float itcpt = ybar - slope * xbar;
  float slopeerr = sqrt ( sy2bar / (ndata * (x2bar - xbar*xbar) ) );
  float itcpterr = sqrt ( x2bar ) * slopeerr;
  cout << "slope of fit line = " << slope << " +- " << slopeerr << endl;
  cout << "intercept of fit line = " << itcpt << " +- " << itcpterr << endl;


  TGraphErrors *mygraph = new TGraphErrors(ndata,x,y,sx,sy);
  mygraph->Draw("A*");

  /*
  TF1 *ffitline = new TF1("ffitline","[0]*x+[1]",0,6); // x ekseninin aralığı [0,6]
  ffitline->SetParameter(0,slope);
  ffitline->SetParameter(1,itcpt);
  ffitline->SetLineColor(kBlue); // draw in blue color
  ffitline->SetLineStyle(2); // draw dotted line
  //ffitline->Draw("same");
  */

  mygraph->SetTitle("; Voltage (V); Counts");


  // let's also try the same with ROOT's own fitter
 // TF1 *fnew = new TF1("fnew","[0]*x+[1]",0,6);
 // fnew->SetParameters(3.1416,2.7182); // arbitrary starting parameters
 // mygraph->Fit("pol2", "F");
 // mygraph->Fit(fnew);


  // TF1 *fpol = mygraph->GetFunction("pol2");
  // fpol->SetLineWidth(1);


  mygraph->Draw("A*");
  

  gStyle->SetOptStat(111110);
  gStyle->SetOptFit(1111);




  


}





