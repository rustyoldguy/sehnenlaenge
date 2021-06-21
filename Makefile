.PHONY: clean All

All:
	@echo "----------Building project:[ sehnenlaenge1 - Debug ]----------"
	@cd "sehnenlaenge1" && "$(MAKE)" -f  "sehnenlaenge1.mk"
clean:
	@echo "----------Cleaning project:[ sehnenlaenge1 - Debug ]----------"
	@cd "sehnenlaenge1" && "$(MAKE)" -f  "sehnenlaenge1.mk" clean
