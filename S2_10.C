 {

    h = new TH1D("h", " ; Number of Counts; Distribution of Counts", 6, 20, 50);
    std::ifstream file("S2_10.txt");
    float datum;
    TGraphErrors gr("S2_10.txt");

    
    while(file>>datum) {
     h->Fill(datum);
     }


    TF1 *fpois = new TF1("fpois","[0]*TMath::Poisson(x,[1])",25,85);
    fpois->SetParameter(1, 54);
    h->Fit("fpois");


    TF1 *fgaus = new TF1("fgaus", "[0]*TMath::Gaus(x, [1], [2])",25,85);
   // fgaus->SetParameters(15, 90, 5);
    h->Fit("fgaus", "+");



    h->SetFillColor(kRed-7);
    h->SetMaximum(45);
    
    gStyle->SetOptStat(111110);
    gStyle->SetOptFit(1111);
    
    h->Draw("E1SAME");
   
}
