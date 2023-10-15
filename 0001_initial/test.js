print_orig=print;
print=function(){};
loadRelativeToScript("support.js");
loadRelativeToScript("main.js");

argc_argv=mk_argc_argv(["out2.exe", "0"]);
print(JSON.stringify(argc_argv));
main(argc_argv.argc,argc_argv.argv);

print=print_orig;

print(vfs["stdout.txt"].map(function(x){return String.fromCharCode(x)}).join(""));

