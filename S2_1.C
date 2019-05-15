 {

    h = new TH1D("h", " ; Number of Counts; Distribution of Counts", 10, 0, 10);
    std::ifstream file("S2_1.txt");
    float datum;
    TGraphErrors gr("S2_1.txt");

    
    while(file>>datum) {
     h->Fill(datum);
     }


    TF1 *fpois = new TF1("fpois","[0]*TMath::Poisson(x,[1])",0,15);
    fpois->SetParameter(1, 5);
    h->Fit("fpois");


    TF1 *fgaus = new TF1("fgaus", "[0]*TMath::Gaus(x, [1], [2])",0,15);
   // fgaus->SetParameters(15, 90, 5);
    h->Fit("fgaus", "+");



    h->SetFillColor(kRed-7);
    h->SetMaximum(35);
    
    gStyle->SetOptStat(111110);
    gStyle->SetOptFit(1111);
    
    h->Draw("E1SAME");
   
}
