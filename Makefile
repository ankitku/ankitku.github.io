html:
	pfiles=("${(@f)$(find posts/*)}")
			
	pandoc -s  my.yaml about.markdown -o about.html --template default.html
	pandoc -s my.yaml 2013-12-01-Droidcon.markdown -o dr.html --template default.html

clean:
	rm -rvf build
