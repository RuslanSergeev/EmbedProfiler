DOXY_EXEC_PATH = /home/ruslan/EmbedPROFILER
DOXYFILE = /home/ruslan/EmbedPROFILER/-
DOXYDOCS_PM = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/DoxyDocs.pm
DOXYSTRUCTURE_PM = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/DoxyStructure.pm
DOXYRULES = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/doxyrules.make
DOXYLATEX_PL = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/doxylatex.pl
DOXYLATEXSTRUCTURE_PL = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/doxylatex-structure.pl
DOXYSTRUCTURE_TEX = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/doxystructure.tex
DOXYDOCS_TEX = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/doxydocs.tex
DOXYFORMAT_TEX = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/doxyformat.tex
DOXYLATEX_TEX = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/doxylatex.tex
DOXYLATEX_DVI = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/doxylatex.dvi
DOXYLATEX_PDF = /home/ruslan/EmbedPROFILER/EmbedPROFILER_doc/perlmod/doxylatex.pdf

.PHONY: clean-perlmod
clean-perlmod::
	rm -f $(DOXYSTRUCTURE_PM) \
	$(DOXYDOCS_PM) \
	$(DOXYLATEX_PL) \
	$(DOXYLATEXSTRUCTURE_PL) \
	$(DOXYDOCS_TEX) \
	$(DOXYSTRUCTURE_TEX) \
	$(DOXYFORMAT_TEX) \
	$(DOXYLATEX_TEX) \
	$(DOXYLATEX_PDF) \
	$(DOXYLATEX_DVI) \
	$(addprefix $(DOXYLATEX_TEX:tex=),out aux log)

$(DOXYRULES) \
$(DOXYMAKEFILE) \
$(DOXYSTRUCTURE_PM) \
$(DOXYDOCS_PM) \
$(DOXYLATEX_PL) \
$(DOXYLATEXSTRUCTURE_PL) \
$(DOXYFORMAT_TEX) \
$(DOXYLATEX_TEX): \
	$(DOXYFILE)
	cd $(DOXY_EXEC_PATH) ; doxygen "$<"

$(DOXYDOCS_TEX): \
$(DOXYLATEX_PL) \
$(DOXYDOCS_PM)
	perl -I"$(<D)" "$<" >"$@"

$(DOXYSTRUCTURE_TEX): \
$(DOXYLATEXSTRUCTURE_PL) \
$(DOXYSTRUCTURE_PM)
	perl -I"$(<D)" "$<" >"$@"

$(DOXYLATEX_PDF) \
$(DOXYLATEX_DVI): \
$(DOXYLATEX_TEX) \
$(DOXYFORMAT_TEX) \
$(DOXYSTRUCTURE_TEX) \
$(DOXYDOCS_TEX)

$(DOXYLATEX_PDF): \
$(DOXYLATEX_TEX)
	pdflatex -interaction=nonstopmode "$<"

$(DOXYLATEX_DVI): \
$(DOXYLATEX_TEX)
	latex -interaction=nonstopmode "$<"
