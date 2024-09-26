PREFIX = /usr/local

shirecal: shirecal.c
	$(CC) shirecal.c -o shirecal

.PHONY: clean
clean:
	$(RM) shirecal

.PHONY: install
install: shirecal
	install		-D shirecal	$(DESTDIR)$(PREFIX)/bin/shirecal

.PHONY: uninstall
unistall:
	$(RM) $(DESTDIR)$(PREFIX)/bin/shirecal
