for(int i = 0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.rbegin(),v.rend());
    while(b!=0){
        b--;
        if(b==1){
            b+=v.back();
            v.pop_back();
        }
        cnt++;
    }
    cout<<cnt<<endl;