 {

    h = new TH1D("h", "; Time (sec); Number of Counts", 12, 0, 4);
    std::ifstream file("par3_n=0.txt");
    float datum;
   
    while(file>>datum) {
    h->Fill(datum);
    }

    h->SetFillColor(kBlue-6);
    h->SetMaximum(50);

    TF1 *f = new TF1("f","[0]*exp(-[1]*x)*[1]",0,5);
    f->SetParameters(1, 1);
    f->SetLineColor(kRed+2);
    h->Fit("f");
    

    gStyle->SetOptStat(111110);
    gStyle->SetOptFit(1111);
    
    h->Draw();
    h->Draw("E1SAME");
    
}