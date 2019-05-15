{

    h = new TH1D("h", "; Time (sec) ; Number of Counts", 10, 0, 4.5);
    std::ifstream file("par3_n=1.txt");
    float datum;
   
    while(file>>datum) {
    h->Fill(datum);
    }

    h->SetFillColor(kBlue-6);
    h->SetMaximum(40);

    TF1 *f = new TF1("f","[0]*exp(-[1]*x)*x*pow([1],2)",0,25);
    f->SetParameters(1, 1);
    f->SetLineColor(kRed+0);
    h->Fit("f");
    
    
    gStyle->SetOptStat(111110);
    gStyle->SetOptFit(1111);
    
    h->Draw();
    h->Draw("E1SAME");
    
}