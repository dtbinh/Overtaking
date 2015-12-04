function r = ref_sel(xin)

% if size(xin, 2) > 100
if xin(1) > 149
    r = 2.5;
else
    xpos = xin(1);
    ref = xin(2:151);

    r = ref(round(xpos)+1);
end

end